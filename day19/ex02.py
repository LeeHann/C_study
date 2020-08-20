#%% 지역 변수의 전역 변수 사용
a=5
def scope_test() :
  global a
  a = 1
  b = 7
  print(a, b)

scope_test()
print(a)
# %% 재귀 함수
count = 5
def recur_test() :
  global count
  if count > 0:
    count = count - 1
    print(count)
    recur_test()

recur_test()
# %% 변수의 함수화
def hello() :
  print('hello')
a = hello
a()
# %% 함수 안 함수
def say() :
  def hello() :
    print('hello')
  hello()

say()