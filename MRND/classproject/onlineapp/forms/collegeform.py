from django import forms
from onlineapp.models import *

class AddCollege(forms.ModelForm):
    class Meta:
        model=College
        exclude=['id']
        widgets={
            'name':forms.TextInput(attrs={'class':'input','placeholder':'enter data'}),
            'location': forms.TextInput(attrs={'class': 'input', 'placeholder': 'enter data'}),
            'acronym': forms.TextInput(attrs={'class': 'input', 'placeholder': 'enter data'}),
            'contact': forms.TextInput(attrs={'class': 'input', 'placeholder': 'enter data'})
        }

class AddStudent(forms.ModelForm):
    class Meta:
        model=Student
        exclude=['id','dob','college']
        widgets={
            'name':forms.TextInput(attrs={'class':'input','placeholder':'enter name'}),
            'email':forms.EmailInput(attrs={'class':'input','placeholder':'enter email'}),
            'db_folder':forms.TextInput(attrs={'class':'input','placeholder':'enter db_folder'}),
            'dropped_out':forms.CheckboxInput(attrs={'class':'input','placeholder':'enter db_folder'}),
            }

class AddMockTest1(forms.ModelForm):
    class Meta:
        model=MockTest1
        exclude=['id','student']
        widgets={
            'problem1': forms.NumberInput(attrs={'class': 'input', 'placeholder': 'enter p1'}),
            'problem2': forms.NumberInput(attrs={'class': 'input', 'placeholder': 'enter p2'}),
            'problem3': forms.NumberInput(attrs={'class': 'input', 'placeholder': 'enter p3'}),
            'problem4': forms.NumberInput(attrs={'class': 'input', 'placeholder': 'enter p4'}),
            'total': forms.NumberInput(attrs={'class': 'input', 'placeholder': 'enter total'}),
        }

class LoginForm(forms.Form):
    username=forms.CharField(
        required=True,
        widget=forms.TextInput(attrs={'class':'input','placeholder':'enter username'})
        )
    password=forms.CharField(
        required=True,
        widget=forms.PasswordInput(attrs={'class':'input','placeholder':'enter password'})
    )

class SignupForm(forms.Form):
    first_name=forms.CharField(
        required=True,
        widget=forms.TextInput(attrs={'class': 'input', 'placeholder': 'enter firstname'})
    )
    last_name=forms.CharField(
        required=True,
        widget= forms.TextInput(attrs={'class': 'input', 'placeholder': 'enter lastname'})
    )
    username = forms.CharField(
        required=True,
        widget= forms.TextInput(attrs={'class': 'input', 'placeholder': 'enter username'})
        )
    password = forms.CharField(
        required=True,
        widget=forms.PasswordInput(attrs={'class': 'input', 'placeholder': 'enter password'})
    )