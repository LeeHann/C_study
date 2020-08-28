from distutils.core import setup, Extension

setup(name="_ex02",
      version="1.0",
      description="hello method sample",
      author="LeeHann",
      author_email="0104ihn@naver.com",
      ext_modules=[Extension(
          "_ex02",
          sources=["ex02_py_mod.c"])]
      )
