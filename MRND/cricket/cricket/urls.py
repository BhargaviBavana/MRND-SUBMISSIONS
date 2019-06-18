"""cricket URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from cricketstas.viewspackage.seasonview import *

urlpatterns = [
    path('admin/', admin.site.urls),
    path('seasons/',SeasonView.as_view(),name="season_view"),
    path('seasons/<int:year>/',SeasonView.as_view(),name="season_view_year"),
    path('seasons/<int:season>/match/<int:match>/',SeasonMatchView.as_view(),name="season_view_year_match"),
    path('login/', LoginView.as_view(), name="login"),
    path('signup/', SignupView.as_view(), name="signup"),
    path('logout/', logout_user, name="logout"),
    path('points/',PointsView.as_view(),name="points"),
    path('points/<int:year>/',PointsView.as_view(),name="points_year"),
]
