#%%
print("숫자를 입력하세요")
a = input()

if int(a) > 0 :
  print('0 보다 크다.')
else :
  print('0 보다 작거나 같다')

# %%
print("요일을 입력하세요.")
strDay = input()

if strDay == '월' :
  print('monday')
  print('----------')
elif strDay == '화' :
  print('fire')
else :
  print('없는 요일 입니다.')

print('********************')
# %%
a = 16
if a > 10 and (a % 2) == 0 :
  print('bingo')
print('finish')
# %%
a = 3
if a == 3 or a == 4 :
  print('3일 수도 있고 4일 수도 있습니다.')
else :
  print('다른 수 입니다.')

# %%
bool('')
bool('aabb')

# %%
print(bool([]))
print(bool([1,2,4]))
