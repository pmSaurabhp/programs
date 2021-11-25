from django import template
register=template.Library()

def custom_filter(value,arg):
    """
    this deletes all the 'arg' from value
    """
    return value.replace(arg,"")   # replaces arg with blank

register.filter('custom_filter',custom_filter)
