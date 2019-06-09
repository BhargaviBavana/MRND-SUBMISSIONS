from django.db import models
from homeproject import settings
# Create your models here.


class Todolist(models.Model):
    name = models.CharField(max_length=255)
    created = models.DateField(auto_now_add=True)
    def __str__(self):
        return self.name

class Todoitem(models.Model):
    description=models.CharField(max_length=255)
    due_date=models.DateField()
    completed=models.BooleanField()
    todolist = models.ForeignKey(Todolist, on_delete=models.CASCADE)
    def __str__(self):
       return self.description