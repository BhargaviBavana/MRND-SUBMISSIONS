from django import forms

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
    photo=forms.ImageField(
        required=True,
        #widget=forms.ImageField(attrs={'class': 'input', 'placeholder': 'enter password'})
    )