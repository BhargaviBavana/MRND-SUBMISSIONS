from django.db import models

# Create your models here.


class Matches(models.Model):
    m_id=models.IntegerField()
    season=models.IntegerField()
    city=models.CharField(max_length=255,null=True)
    date=models.DateField()
    team1=models.CharField(max_length=255)
    team2=models.CharField(max_length=255)
    toss_winner=models.CharField(max_length=255)
    toss_decision=models.CharField(max_length=255)
    result=models.CharField(max_length=255,null=True)
    dl_applied=models.IntegerField(null=True)
    winner=models.CharField(max_length=255,null=True)
    win_by_runs=models.IntegerField(null=True)
    win_by_wickets=models.IntegerField(null=True)
    player_of_match=models.CharField(max_length=255,null=True)
    venue=models.CharField(max_length=255)
    umpire1=models.CharField(max_length=255,null=True)
    umpire2=models.CharField(max_length=255,null=True)
    umpire3=models.CharField(max_length=255,null=True)

class Deliveries(models.Model):
    match_id=models.ForeignKey(Matches,on_delete=models.CASCADE)
    inning=models.IntegerField()
    beating_team=models.CharField(max_length=255)
    bowling_team=models.CharField(max_length=255)
    over=models.IntegerField()
    ball=models.IntegerField()
    batsman=models.CharField(max_length=255)
    non_sticker=models.CharField(max_length=255)
    bowler=models.CharField(max_length=255)
    is_super_over=models.IntegerField(null=True)
    wide_runs=models.IntegerField(null=True)
    bye_runs=models.IntegerField(null=True)
    legbye_runs=models.IntegerField(null=True)
    nonball_runs=models.IntegerField(null=True)
    penalty_runs=models.IntegerField(null=True)
    batsman_runs=models.IntegerField(null=True)
    extra_runs=models.IntegerField(null=True)
    total_runs=models.IntegerField(null=True)
    player_dismissed=models.CharField(max_length=255,null=True)
    dismissal_kind=models.CharField(max_length=255,null=True)
    fielder=models.CharField(max_length=255,null=True)







