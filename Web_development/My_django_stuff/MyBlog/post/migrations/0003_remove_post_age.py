# Generated by Django 3.0.3 on 2020-05-12 09:11

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('post', '0002_post_age'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='post',
            name='age',
        ),
    ]
