
from django.contrib import admin
from django.conf import settings
from django.urls import include, path,re_path  # For django versions from 2.0 and up
from onlineapp import views
urlpatterns = [ path('get_my_college/', views.getmycollege,name="get_my_college"),
                path('get_all_colleges/', views.getallcolleges,name="get_all_college"),
                path('<int:id>/',views.getcollegeinformation)
                ]