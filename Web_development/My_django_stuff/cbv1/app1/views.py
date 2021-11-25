from django.shortcuts import render
# Create your views here.
from django.http import HttpResponse
from django.views.generic import View,TemplateView,ListView,DetailView,CreateView,UpdateView,DeleteView
from app1 import models
from django.urls import reverse_lazy,reverse

#class CBView(View):
#    def get(self,request):
#        return HttpResponse("CLASS BASE VIEWS are better")

# class CBView(TemplateView):
#     template_name='app1/index.html'
#
#     def get_context_data(self,**kwargs):              # **kwargs is used to represent any no. of arguments in dictionary
#         context=super().get_context_data(**kwargs)
#
#         context['injectme']='I was inserted through class base view'
#         return context
class CBView(TemplateView):                 # template_name carries file location path
    template_name='app1/index.html'        # django first checks in cbv1/templates/app1/
                                          # if html file is not found it searches for file name with templates in app1 directory
class SchoolListView(ListView):
    context_object_name='school_list'
    model=models.School
    template_name='school_list.html'      # by default template_name stores built in names for html file
                                          # its changed like this

class SchoolDetailView(DetailView):
    context_object_name='school_detail'   # context dictionary
    model=models.School
    template_name='app1/school_detail.html'

class SchoolCreateView(CreateView):
    model=models.School
    fields='__all__'
    context_object_name='insert_create'
    # school_form.html comes as default template_name
class SchoolUpdateView(UpdateView):
    model=models.School
    context_object_name='update'
    fields={'school_name','principal'}
    template_name='app1/school_form.html'     # by default
class SchoolDeleteView(DeleteView):
    model=models.School
    context_object_name='delete'
    success_url=reverse_lazy('app1:list')    # reverse_lazy redirect to list.html after successfull deletion
