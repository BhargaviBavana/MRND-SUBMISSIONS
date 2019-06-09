import click
import openpyxl
import os
import django
os.environ.setdefault('DJANGO_SETTINGS_MODULE','homeproject.settings')
django.setup()
import datetime
from todoapp.models import *

@click.group()
def main():
    pass

@main.command()
@click.argument('excelfile',nargs=1)
def populatedatabase(excelfile):
    l_list=get_data(excelfile,'list')
    i_list=get_data(excelfile,'item')

    for l in l_list:
        try:
            #print(l[0])
            obj=Todolist(name=l[0])
            obj.save()
        except Exception:
            pass

    for i in i_list:
        try:
            #print(i[0], i[1], i[2], i[3])
            date_time=i[2].split(' ')
            d=date_time[0]
            c=i[3]
            if(c=='true'):
                obj = Todoitem(todolist=Todolist.objects.get(name=i[0]), description=i[1], due_date=d, completed=True)
                obj.save()
            else:
                obj = Todoitem(todolist=Todolist.objects.get(name=i[0]), description=i[1], due_date=d, completed=False)
                obj.save()
        except Exception:
            pass


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

    for i in range(min_row,max_row+1):
        l=[]
        for j in range(min_col,max_col+1):
            l.append(str(sheet.cell(row=i, column=j).value).lower())
        list_data.append(l)

    return list_data


if __name__=='__main__':
    main()