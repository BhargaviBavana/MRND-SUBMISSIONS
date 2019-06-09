import click
import openpyxl
import os
import django
os.environ.setdefault('DJANGO_SETTINGS_MODULE','classproject.settings')
django.setup()

from onlineapp.models import *

@click.group()
def main():
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

    for i in range(min_row+1,max_row+1):
        l=[]
        for j in range(min_col,max_col+1):
            l.append(str(sheet.cell(row=i, column=j).value).lower())
        list_data.append(l)

    return list_data


@main.command()
@click.argument('excel_file',nargs=1)
@click.argument('html_file',nargs=1)
def insertdata(excel_file,html_file):
    college_data=get_data(excel_file,"Colleges")
    student_data=get_data(excel_file,"Current")
    deletion_data=get_data(excel_file,"Deletions")
    marks_data=get_data(html_file,"marksheet")
    '''for clg_data in college_data:
        print(clg_data[0],clg_data[1],clg_data[2],clg_data[3])

    print()
    for s_data in student_data:
        print(s_data[0],s_data[1],s_data[2],s_data[3])

    print()
    for m_data in marks_data:
        print(m_data[0],m_data[1],m_data[2],m_data[3],m_data[4],m_data[5])'''

    for clg_data in college_data:
        try:
            #print(clg_data[0], clg_data[1], clg_data[2], clg_data[3])
            obj=College(name=clg_data[0],location=clg_data[2],acronym=clg_data[1],contact=clg_data[3])
            obj.save()
        except Exception:
            pass

    for s_data in student_data:
        try:
            #print(s_data[0], s_data[1], s_data[2], s_data[3])
            if isPresent(s_data[3],deletion_data):
                obj= Student(name=s_data[0],email=s_data[2],db_folder=s_data[3],dropped_out=True,college=College.objects.get(acronym=s_data[1]))
                obj.save()
            else:
               obj= Student(name=s_data[0],  email=s_data[2], db_folder=s_data[3], dropped_out=False, college=College.objects.get(acronym=s_data[1]))
               obj.save()
        except Exception:
            pass
    for m_data in marks_data:
        try:
            #print(m_data[0], m_data[1], m_data[2], m_data[3], m_data[4], m_data[5])
            name=m_data[0]
            l=name.split('_')
            dbname=l[2]
            obj=MockTest1(problem1=m_data[1],problem2=m_data[2],problem3=m_data[3],problem4=m_data[4],total=m_data[5],student=Student.objects.get(db_folder=dbname))
            obj.save()
        except Exception:
            pass

def isPresent(name,deletion_data):
    for d_data in deletion_data:
        if name==d_data[3]:
            return True
    return False


if __name__=='__main__':
    main()