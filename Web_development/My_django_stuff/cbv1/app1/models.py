from django.db import models
from django.urls import reverse

# Create your models here.
class School(models.Model):
    school_name=models.CharField(max_length=256)
    principal=models.CharField(max_length=256)
    location=models.CharField(max_length=256)

    def __str__(self):
        return self.school_name
    def get_absolute_url(self):                       # when submit is clicked which html page should be opened 
        return reverse('app1:detail',kwargs={'pk':self.pk})

class Student(models.Model):
    student_name=models.CharField(max_length=256)
    age=models.PositiveIntegerField()
    school_name=models.ForeignKey(School,related_name='students',on_delete=models.CASCADE)

    def __str__(self):
        return self.student_name
