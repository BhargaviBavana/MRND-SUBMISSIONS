from django.shortcuts import render
from django.http import HttpResponse
from django.template import Context, loader
from onlineapp.models import *
# Create your views here.

def hello_world(request):
   #return HttpResponse("hello world")
   return HttpResponse(render(request,"hello.html"))

def getmycollege(request):
    '''c=College.objects.values_list('name','location','acronym','contact').filter(acronym='gvp')
    html="""<body><table>"""
    for n,l,a,c in c:
       html+="<tr><td>"+n+"</td><td>"+l+"</td><td>"+a+"</td><td>"+c+"</td></tr>"
    html+="</table></body>"
    return HttpResponse(html)'''
    my_dict = College.objects.values_list('name', 'location', 'acronym', 'contact').filter(acronym='gvp')
    return HttpResponse(render(request, 'getmycollege.html', context={'my_dict': my_dict}))

def getallcolleges(request):
    #c=College.objects.values_list('acronym','name')
    #html="""<body><table>"""
    #for a,n in c:
     #   html+="<tr><td>"+a+"</td><td>"+n+"</td></tr>"
    #html+="</table></body>"
    #return HttpResponse(html)

    my_dict = College.objects.values_list('id','acronym', 'name')
    return HttpResponse(render(request,'getallcolleges.html',context={'my_dict':my_dict}))

def getcollegeinformation(request,id):
    my_dict=MockTest1.objects.values_list('student__name', 'total').filter(student__college__id=id)
    return HttpResponse(render(request,"getcollegeinformation.html",context={'my_dict':my_dict}))
