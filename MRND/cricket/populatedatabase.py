
import click
import openpyxl
import os
import django
os.environ.setdefault('DJANGO_SETTINGS_MODULE','cricket.settings')
django.setup()
from cricketstas.models import *

@click.group()
def main():
    pass

@main.command()
@click.argument('matches',nargs=1)
@click.argument('deliveries',nargs=1)
def populate(matches,deliveries):
    #m_list=get_data(matches,'m')
    d_list=get_data(deliveries,'deliveries')

    '''for l in m_list:
        try:
            d1=l[3].split(' ')
            m_id = int(l[0])
            season = int(l[1])
            city = l[2]
            date =d1[0]
            team1 = l[4]
            team2 = l[5]
            toss_winner = l[6]
            toss_decision = l[7]
            result = l[8]
            dl_applied = int(l[9])
            winner = l[10]
            win_by_runs = int(l[11])
            win_by_wickets = int(l[12])
            player_of_match = l[13]
            venue = l[14]
            umpire1 = l[15]
            umpire2 = l[16]
            umpire3 = l[17]
            obj=Matches(m_id=m_id,season=season,city=city,date=date,team1=team1,team2=team2,toss_winner=toss_winner,toss_decision=toss_decision,result=result,
                        dl_applied=dl_applied,winner=winner,win_by_runs=win_by_runs,win_by_wickets=win_by_wickets,player_of_match=player_of_match,venue=venue
                        ,umpire1=umpire1,umpire2=umpire2,umpire3=umpire3)
            obj.save()
        except Exception as e:
            print("in matches populate excption occured",e)'''

    for l in d_list:
        try:
            match_id = Matches.objects.get(m_id=int(l[0]))
            inning = int(l[1])
            beating_team = l[2]
            bowling_team = l[3]
            over = int(l[4])
            ball = int(l[5])
            batsman = l[6]
            non_sticker = l[7]
            bowler = l[8]
            is_super_over = int(l[9])
            wide_runs = int(l[10])
            bye_runs = int(l[11])
            legbye_runs = int(l[12])
            nonball_runs = int(l[13])
            penalty_runs = int(l[14])
            batsman_runs = int(l[15])
            extra_runs = int(l[16])
            total_runs = int(l[17])
            player_dismissed = l[18]
            dismissal_kind = l[19]
            fielder = l[20]
            obj=Deliveries(match_id=match_id,inning=inning,beating_team=beating_team,bowling_team=bowling_team,over=over,ball=ball,batsman=batsman,
                           non_sticker=non_sticker,bowler=bowler,is_super_over=is_super_over,wide_runs=wide_runs,bye_runs=bye_runs,
                           legbye_runs=legbye_runs,nonball_runs=nonball_runs,penalty_runs=penalty_runs,batsman_runs=batsman_runs,extra_runs=extra_runs,
                           total_runs=total_runs,player_dismissed=player_dismissed,dismissal_kind=dismissal_kind,fielder=fielder)
            obj.save()
        except Exception as e:
            print(e)




def get_data(file,sheetName):
    book = openpyxl.load_workbook(file)
    sheet = book.get_sheet_by_name(sheetName)
    dim = sheet.dimensions
    (s1, s2) = dim.split(':')
    min_col = ord(s1[0]) - 64
    min_row = int(s1[1:])
    max_col = ord(s2[0]) - 64
    max_row = int(s2[1:])

    list_data=[]

    for i in range(min_row+1,max_row+1):
        l=[]
        for j in range(min_col,max_col+1):
            l.append(str(sheet.cell(row=i, column=j).value).lower())
        list_data.append(l)

    return list_data





if __name__=='__main__':
    main()