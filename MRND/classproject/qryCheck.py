import os
import django
os.environ.setdefault('DJANGO_SETTINGS_MODULE','classproject.settings')
django.setup()
from onlineapp.models import *

c=College.objects.all()
print(c)

print(c)