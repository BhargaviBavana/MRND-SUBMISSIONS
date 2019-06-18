from django.views import View
from django.shortcuts import render,redirect
from cricketstas.models import *
from django.core.paginator import Paginator,PageNotAnInteger,EmptyPage
from django.db.models import *
from django.contrib.auth.mixins import LoginRequiredMixin
from django.contrib.auth import authenticate,login,logout
from django.contrib.auth.models import User
from cricketstas.forms.authform import *

class SeasonView(View):
    def get(self,request,*args,**kwargs):

        if kwargs:
            matches_in_season = Matches.objects.values_list('m_id','team1', 'team2', 'venue', 'toss_winner', 'toss_decision',
                                                            'result', 'player_of_match').filter(season=kwargs['year'])
            paginator=Paginator(matches_in_season,8)
            page = request.GET.get('page')
            try:
                queryset = paginator.page(page)
            except PageNotAnInteger:
                queryset = paginator.page(1)
            except EmptyPage:
                queryset = paginator.page(paginator.num_pages)

            return render(request,
                          template_name='matchesinseason.html',
                          context={"match_list": queryset,'season':kwargs['year'],}
                          )
        else:
             matches_in_season=Matches.objects.values_list('m_id','team1','team2','venue','toss_winner','toss_decision','result','player_of_match').filter(season=2019)
             paginator = Paginator(matches_in_season, 8)
             page = request.GET.get('page')
             try:
                 queryset = paginator.page(page)
             except PageNotAnInteger:
                 queryset = paginator.page(1)
             except EmptyPage:
                 queryset = paginator.page(paginator.num_pages)

             return render(request,
                           template_name='matchesinseason.html',
                           context={"match_list": queryset, 'season':2019, }
                           )
class SeasonMatchView(LoginRequiredMixin,View):
    login_url = '/login/'
    def get(self,request,*args,**kwargs):
        match_details=Matches.objects.values_list('team1','team2','toss_winner','toss_decision','result','win_by_runs','win_by_wickets','player_of_match').filter(m_id=kwargs['match'])
        ball_details=Deliveries.objects.values_list('ball','total_runs','dismissal_kind').filter(match_id__m_id=kwargs['match'])
        top3_run_scores= Deliveries.objects.values_list('batsman', 'beating_team').annotate(sum=Sum('batsman_runs')).order_by(
            '-sum').filter(match_id__m_id=kwargs['match'])[:3]
        top3_wicket_takers = Deliveries.objects.values_list('bowler', 'bowling_team').annotate(count=Count('dismissal_kind')).order_by(
            '-count').filter(match_id__m_id=kwargs['match']).exclude(dismissal_kind__exact='none')[:3]
        ball_details_inning1 = Deliveries.objects.values_list('ball', 'total_runs', 'dismissal_kind').filter(
            match_id__m_id=kwargs['match']).filter(inning=1)
        ball_details_inning2 = Deliveries.objects.values_list('ball', 'total_runs', 'dismissal_kind').filter(
            match_id__m_id=kwargs['match']).filter(inning=2)

        return render(request,
                      template_name='matchdetails.html',
                      context={'match_details': match_details, 'ball_details': ball_details,'top3_run_scores':top3_run_scores,
                      'top3_wicket_takers':top3_wicket_takers,'match':kwargs['match'],'ball_details_inning1':ball_details_inning1,
                        'ball_details_inning2':ball_details_inning2,}
                      )

class LoginView(View):
    def get(self,request,*args,**kwargs):
        login_form = LoginForm()
        return render(
            request,
            template_name="login.html",
            context={'login_form':login_form}
        )
    def post(self,request,*args,**kwargs):
        login_form=LoginForm(request.POST)
        if login_form.is_valid():
            #print("correct")
            user=authenticate(request,username=request.POST['username'],password=request.POST['password'])
            if user is not None:
                login(request,user)
                #my_dict = College.objects.all()
                return redirect("season_view")
            else:
                login_form = LoginForm()
                return render(
                    request,
                    template_name="login.html",
                    context={'login_form': login_form}
                )
        else:
            login_form = LoginForm()
            return render(
                request,
                template_name="login.html",
                context={'login_form': login_form}
            )


class SignupView(View):
    def get(self,request,*args,**kwargs):
        signup_form = SignupForm()
        return render(
            request,
            template_name="signup.html",
            context={'signup_form':signup_form}
        )
    def post(self,request,*args,**kwargs):
        signup_form=SignupForm(request.POST)
        if signup_form.is_valid():
            user=User.objects.create_user(**signup_form.cleaned_data)
            user.save()
            if user is not None:
                login(request,user)
                return redirect("login")
            else:
                return redirect("signup")
        else:
            return redirect("signup")

def logout_user(request):
    logout(request)
    return redirect("login")

class PointsView(View):
    def get(self,request,*args,**kwargs):
        if kwargs:
            obj1 =Matches.objects.values_list('winner').annotate(count=Count('winner')).filter(result='normal').filter(season=kwargs['year'])
            obj1_dict=dict(obj1)
            obj2=Matches.objects.values_list('team1','team2').annotate(count=Count('winner')).filter(result='tie').filter(season=kwargs['year'])
            for key in obj1_dict.keys():
                obj1_dict[key]=obj1_dict[key]*2
            for row in obj2:
                if row[0] in obj1_dict.keys():
                    obj1_dict[row[0]]+=1
                else:
                    obj1_dict[row[0]]=1
                if row[1] in obj1_dict.keys():
                    obj1_dict[row[1]] += 1
                else:
                    obj1_dict[row[1]] = 1
            points_info=[(key,obj1_dict[key]) for key in obj1_dict.keys()]
            return render(request,
                template_name="pointstable.html",
                context={'points_info':points_info,}
            )
        else:
            obj1 = Matches.objects.values_list('winner').annotate(count=Count('winner')).filter(result='normal').filter(
                season=2019)
            obj1_dict = dict(obj1)
            obj2 = Matches.objects.values_list('team1', 'team2').annotate(count=Count('winner')).filter(
                result='tie').filter(season=2019)
            for key in obj1_dict.keys():
                obj1_dict[key] = obj1_dict[key] * 2
            for row in obj2:
                if row[0] in obj1_dict.keys():
                    obj1_dict[row[0]] += 1
                else:
                    obj1_dict[row[0]] = 1
                if row[1] in obj1_dict.keys():
                    obj1_dict[row[1]] += 1
                else:
                    obj1_dict[row[1]] = 1
            points_info = [(key, obj1_dict[key]) for key in obj1_dict.keys()]
            return render(request,
                          template_name="pointstable.html",
                          context={'points_info': points_info, }
                          )





