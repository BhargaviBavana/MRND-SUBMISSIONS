from onlineapp.view import *
from django.contrib import admin
from django.conf import settings
from django.urls import include, path,re_path  # For django versions from 2.0 and up
from . import view
from onlineapp.view.college import *

#from onlineapp import views
urlpatterns = [ #path('get_my_college/', views.getmycollege,name="get_my_college"),
                #path('get_all_colleges/', views.getallcolleges,name="get_all_college"),
                #path('<int:id>/',views.getcollegeinformation)

                path('testpath/',my_first_view,name="first"),

                path('colleges/',CollegeView.as_view(),name="colleges"),
                path('colleges/<str:acronym>/', CollegeView.as_view(), name="college_details"),
                path('college/add/',CollegeAdd.as_view(),name="college_add"),
                path('college/edit/<int:id>/',CollegeAdd.as_view(),name="college_edit"),
                path('college/delete/<int:id>/',CollegeAdd.as_view(),name="college_delete"),
                path('student/add/<str:acronym>/',StudentAdd.as_view(),name="student_add"),
                path('student/edit/<str:acronym>/<int:id>/', StudentAdd.as_view(), name="student_edit"),
                path('student/delete/<str:acronym>/<int:id>/', StudentAdd.as_view(), name="student_delete"),
                path('api/v1/colleges/',rest_college,name="rest_college"),
                path('api/v1/college/<int:id>/',rest_college,name="rest_college_id"),
                path('api/v1/college/<int:id>/students/',RestCollegeInfomation.as_view(),name="rest_college_information"),
                path('api/v1/college/<int:cid>/student/<int:sid>/',RestCollegeInfomation.as_view(),name='rest_student_information'),
                path('api/v1/tokens/',ViewToken.as_view(),name="view_token"),
                path('api/v1/searchbar/',SearchBar.as_view(),name="search_bar"),
]