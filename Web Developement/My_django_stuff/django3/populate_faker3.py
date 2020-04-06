import os
os.environ.setdefault('DJANGO_SETTINGS_MODULE','django3.settings')

import django
django.setup()

import random
from app3.models import User
from faker import Faker

fake_obj=Faker()     # object of faker class is made


def populate(N=5):
    for entry in range(N):


        #create fake data
        fake_name=fake_obj.name().split()   # fakegen()  creates fake data
        fake_fname=fake_name[0]
        fake_lname=fake_name[1]
        fake_email=fake_obj.email()

        #create new webpage entry
        fake_user=User.objects.get_or_create(first_name=fake_fname,last_name=fake_lname,email=fake_email)[0]
             # get_or_create() puts the data into User object ( User.objects  )


if __name__=="__main__":                  # populate() will run only when python manage.py populate_faker3
        print("populate script")          # if it is imported in other file it will not run
        populate(10)
        print("populate complete")
