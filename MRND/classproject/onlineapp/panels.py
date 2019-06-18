from debug_toolbar.panels import DebugPanel
from django.template.loader import render_to_string
from django.utils.translation import ugettext_lazy as _
import os
import psutil
import sys

from onlineapp.models import *
class MyPanel(DebugPanel):
    name = 'MyPanel'
    has_content = True

    @property
    def nav_title(self):
        return _('Process Infos')

    @property
    def title(self):
        return _('My Panel')

    @property
    def content(self):
        pid=os.getpid()
        p=psutil.Process(pid)

        name=p.name()
        ws=p.memory_info().rss
        vm=p.cpu_percent()

        p=ProcessInfo(pid=pid,name=name,ws=ws,vm=vm)
        p.save()

        my_dict=ProcessInfo.objects.all()

        return render_to_string('panels/processinfo.html', {'pid':os.getpid(),'path':sys.path,'my_dict':my_dict,})