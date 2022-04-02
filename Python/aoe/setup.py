from distutils.core import setup 
import py2exe 
 
setup(name="qbert", 
 version="1.0", 
 description="jogra", 
 author="Vicente Alves", 
 author_email="loshaywinover@gmail.com", 
 url="url del proyecto", 
 license="tipo de licencia", 
 scripts=["qbert.py"], 
 console=["qbert.py"], 
 options={"py2exe": {"bundle_files": 1}}, 
 zipfile=None,
)
#https://geekytheory.com/generar-un-ejecutable-exe-a-partir-de-un-py
