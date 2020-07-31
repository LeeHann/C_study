# -*- coding: utf-8 -*-

# "와 '의 구분 없이 사용 가능
_a = 'hello hello llo eelo llo halo llo'
_b = 'libex04'
_c = 'libex03'

# 접두사 확인
_a.startswith('he') # True
_b.startswith('lib') # True

# 접미사 확인
_a.endswith('lo') # True

# 문자열 내 키워드 위치 출력
_c.find('ex') # 3

# 문자열 내 키워드 반복 횟수 출력
_a.count('llo') # 5

_lt = "      front line       "

str.lstrip(_lt) # 'front line       ' 앞 공백없이 출력
str.rstrip(_lt) # '      front line' 뒷 공백없이 출력

_lt.lstrip() # 'front line       ' 앞 공백 삭제
_lt.rstrip() # 'front line' 뒷 공백 삭제

# 문자열인지 확인
print(str.isalpha('hello')) # True

# 정수형 확인
print(str.isdigit('hello')) # False
print(str.isdigit('3.14')) # False
print(str.isdigit('314')) # True

print(str.isdecimal('100')) # True

# formatted string
name = "hanna"
age = 22
print(f'my name {name} my age {age}') # my name hanna my age 22

# split 띄어쓰기로 배열 구분
data = "lee hanna"
_data = data.split()

print(_data[0]) # lee
print(_data[1]) # hanna

data = "kor/eng/math/the society"
data.split('/') # /, ' ' 단위로 배열 구분

data = input()
data.split()