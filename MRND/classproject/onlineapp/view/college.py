from django.views import View
from django.shortcuts import render,redirect
from onlineapp.models import *
from onlineapp.templates import *
from onlineapp.forms.collegeform import *
from django.urls import resolve
from django.contrib.auth import authenticate,login,logout
from django.contrib.auth.models import User
from django.http import HttpResponse
from django.contrib.auth.mixins import LoginRequiredMixin
from onlineapp.serilizer import *
from rest_framework.response import Response
from rest_framework.decorators import api_view
from rest_framework import status
from rest_framework.views import APIView
from rest_framework.decorators import api_view, permission_classes
from rest_framework.permissions import IsAuthenticated,IsAdminUser,IsAuthenticatedOrReadOnly
from rest_framework.authtoken.models import Token
import logging

class CollegeView(LoginRequiredMixin,View):
    login_url ='/login/'

    def get(self, request, *args, **kwargs):
        if kwargs:
            # college=College.objects.filter(**kwargs)
            # print(kwargs['id'])
            my_dict = MockTest1.objects.values_list('student__name', 'total','student__college__acronym','student__id').filter(
                student__college__acronym=kwargs['acronym'])
            permissions = request.user.get_all_permissions()
            return render(
                request,
                template_name='getcollegeinformation.html',
                context={'my_dict': my_dict, 'acronym':kwargs['acronym'],'permissions':permissions}
            )
        else:
            logging.debug("Debug Message")
            logging.error("Eroor Message")
            logging.info("Info message")
            my_dict = College.objects.all()
            permissions=request.user.get_all_permissions()

            return render(
                request,
                template_name="getallcolleges1.html",
                context={'my_dict': my_dict,'permissions':permissions}
            )


class CollegeAdd(LoginRequiredMixin,View):
    login_url = '/login/'
    def get(self, request, *args, **kwargs):
        if(resolve(request.path_info).url_name=='college_delete'):
            College.objects.get(id=kwargs['id']).delete()
            my_dict = College.objects.all()
            permissions = request.user.get_all_permissions()
            return render(
                request,
                template_name="getallcolleges1.html",
                context={'my_dict': my_dict,'permissions':permissions}
            )
        else:
            form = AddCollege()
            permissions = request.user.get_all_permissions()
            return render(
                request,
                template_name="formsubmit.html",
                context={'form': form, }
            )

    def post(self, request, *args, **kwargs):
        if(resolve(request.path_info).url_name=='college_edit'):
                college=College.objects.get(id=kwargs['id'])
                form=AddCollege(request.POST,instance=college)
                if(form.is_valid()):
                    form.save()
                my_dict = College.objects.all()
                permissions = request.user.get_all_permissions()
                return render(
                    request,
                    template_name="getallcolleges1.html",
                    context={'my_dict': my_dict,'permissions':permissions}
                )
        else:
            form = AddCollege(request.POST)
            #print(my_dict)
            if form.is_valid():
                form.save()
                my_dict = College.objects.all()
                permissions = request.user.get_all_permissions()
                return render(
                    request,
                    template_name="getallcolleges1.html",
                    context={'my_dict': my_dict ,'permissions':permissions}
                )
class StudentAdd(LoginRequiredMixin,View):
    login_url = '/login/'
    def get(self,request,*args,**kwargs):
        if (resolve(request.path_info).url_name == 'student_delete'):
            s = Student.objects.get(id=kwargs['id'])
            m = MockTest1.objects.get(student=s).delete()
            s.delete()
            my_dict = MockTest1.objects.values_list('student__name', 'total', 'student__college__acronym',
                                                    'student__id').filter(
                student__college__acronym=kwargs['acronym']
            )
            permissions = request.user.get_all_permissions()
            return render(
                request,
                template_name="getcollegeinformation.html",
                context={'my_dict': my_dict, 'acronym': kwargs['acronym'],'permissions':permissions})

        else:
                form1=AddStudent()
                form2=AddMockTest1()
                return render(
                    request,
                    template_name="studentsubmit.html",
                    context={'form1':form1,'form2':form2}
                )
    def post(self,request,*args,**kwargs):
        if (resolve(request.path_info).url_name == 'student_edit'):
            s=Student.objects.get(id=kwargs['id'])
            form1=AddStudent(request.POST,instance=s)
            if form1.is_valid():
                form1.save()
            else:
                return
            m = MockTest1.objects.get(student=s)
            form2 = AddMockTest1(request.POST, instance=m)
            if  form2.is_valid():
                form2.save()
            else:
                return
            my_dict = MockTest1.objects.values_list('student__name', 'total','student__college__acronym','student__id').filter(
                student__college__acronym=kwargs['acronym'])
            permissions = request.user.get_all_permissions()
            return render(
                    request,
                    template_name="getcollegeinformation.html",
                    context={'my_dict':my_dict,'acronym':kwargs['acronym'],'permissions':permissions}
                )
        else:
            c=College.objects.get(acronym=kwargs['acronym'])
            student1=Student(college=c)
            form1=AddStudent(request.POST,instance=student1)
            if form1.is_valid():
                form1.save()
            else:
                return
            mocktest1=MockTest1(student=student1)
            form2=AddMockTest1(request.POST,instance=mocktest1)
            #print(type(my_dict1),my_dict1)
            #print(type(my_dict2),my_dict2)
            #print(form1.Meta.widgets['name'])
            print(form1.is_valid(),form2.is_valid())
            if  form2.is_valid():
                form2.save()
            else:
                return
            my_dict = MockTest1.objects.values_list('student__name', 'total','student__college__acronym','student__id').filter(
                student__college__acronym=kwargs['acronym']
            )
            permissions = request.user.get_all_permissions()
            return render(
                    request,
                    template_name="getcollegeinformation.html",
                    context={'my_dict':my_dict,'acronym':kwargs['acronym'],'permissions':permissions}
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
            print("correct")
            user=authenticate(request,username=request.POST['username'],password=request.POST['password'])
            if user is not None:
                login(request,user)
                #my_dict = College.objects.all()
                return redirect("colleges")
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
            template_name="singup.html",
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

@api_view(['GET','POST','PUT','DELETE'])
@permission_classes((IsAuthenticatedOrReadOnly, ))
def rest_college(request,*args,**kwargs):
    if request.method=='GET':
        if(kwargs):
            c=College.objects.get(id=kwargs['id'])
            c = CollegeSerializer(c)
            return Response(c.data)
        else:
            college=College.objects.all()
            c=CollegeSerializer(college,many=True)
            return Response(c.data)
    if request.method=='POST':
        c=CollegeSerializer(data=request.data)
        if c.is_valid():
            c.save()
            return Response(c.data, status=status.HTTP_201_CREATED)
        return Response(c.errors, status=status.HTTP_400_BAD_REQUEST)
    if request.method=='PUT':
        c=College.objects.get(id=kwargs['id'])
        cs=CollegeSerializer(data=request.data,instance=c)
        if cs.is_valid():
            cs.save()
            return Response(cs.data, status=status.HTTP_202_ACCEPTED)
        return Response(cs.errors, status=status.HTTP_400_BAD_REQUEST)
    if request.method=='DELETE':
        c=College.objects.get(id=kwargs['id'])
        c.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)

class RestCollegeInfomation(APIView):
    permission_classes = (IsAuthenticated,)
    def get(self,request,*args,**kwargs):
        college_information=MockTest1.objects.all().filter(student__college__id=kwargs['id'])
        c = CollegeInformationSerializer(college_information, many=True)
        return Response(c.data)
    def post(self,request,*args,**kwargs):
        c = CollegeInformationSerializer(data=request.data,context={'id':kwargs['id']})
        if c.is_valid():
            c.save()
            return Response(c.data, status=status.HTTP_201_CREATED)
        return Response(c.errors, status=status.HTTP_400_BAD_REQUEST)
    def put(self,request,*args,**kwargs):
        mocktest1=MockTest1.objects.get(student__id=kwargs['sid'])
        c = CollegeInformationSerializer(data=request.data, instance=mocktest1,context={'cid': kwargs['cid'],'sid':kwargs['sid']})
        if c.is_valid():
            c.save()
            return Response(c.data, status=status.HTTP_201_CREATED)
        return Response(c.errors, status=status.HTTP_400_BAD_REQUEST)

    def delete(self,request,*args,**kwargs):
        s=Student.objects.get(id=kwargs['sid'])
        s.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)



def my_first_view(request):
    return HttpResponse(request,"response")


class ViewToken(APIView):
    def post(self,request,*args,**kwargs):
        token=Token.objects.create(user=request.data['username'],password=request.data['password'])
        return HttpResponse(str(token.key))


class SearchBar(APIView):
    def get(self,request,*args,**kwargs):
        return render(
            request,
            template_name="searchbar.html",
            )










