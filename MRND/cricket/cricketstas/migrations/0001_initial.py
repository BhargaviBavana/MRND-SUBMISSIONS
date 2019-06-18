# Generated by Django 2.2.1 on 2019-06-17 05:55

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Matches',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('m_id', models.IntegerField()),
                ('season', models.IntegerField()),
                ('city', models.CharField(max_length=255)),
                ('date', models.DateField()),
                ('team1', models.CharField(max_length=255)),
                ('team2', models.CharField(max_length=255)),
                ('toss_winner', models.CharField(max_length=255)),
                ('toss_decision', models.CharField(max_length=255)),
                ('result', models.CharField(max_length=255)),
                ('dl_applied', models.IntegerField()),
                ('winner', models.CharField(max_length=255)),
                ('win_by_runs', models.IntegerField()),
                ('win_by_wickets', models.IntegerField()),
                ('player_of_match', models.CharField(max_length=255)),
                ('venue', models.CharField(max_length=255)),
                ('umpire1', models.CharField(max_length=255)),
                ('umpire2', models.CharField(max_length=255)),
                ('umpire3', models.CharField(max_length=255)),
            ],
        ),
        migrations.CreateModel(
            name='Deliveries',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('inning', models.IntegerField()),
                ('beating_team', models.CharField(max_length=255)),
                ('bowling_team', models.CharField(max_length=255)),
                ('over', models.IntegerField()),
                ('ball', models.IntegerField()),
                ('bastman', models.CharField(max_length=255)),
                ('non_sticker', models.CharField(max_length=255)),
                ('bowler', models.CharField(max_length=255)),
                ('is_super_over', models.IntegerField()),
                ('wide_runs', models.IntegerField()),
                ('bye_runs', models.IntegerField()),
                ('legbye_runs', models.IntegerField()),
                ('nonball_runs', models.IntegerField()),
                ('penalty_runs', models.IntegerField()),
                ('bastman_runs', models.IntegerField()),
                ('extra_runs', models.IntegerField()),
                ('total_runs', models.IntegerField()),
                ('player_dismissed', models.CharField(max_length=255)),
                ('dismissal_kind', models.CharField(max_length=255)),
                ('fielder', models.CharField(max_length=255)),
                ('match_id', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, to='cricketstas.Matches')),
            ],
        ),
    ]