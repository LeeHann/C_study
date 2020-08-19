#%%
limit = 3
count = 0
while count < limit :
  print('repeat!')
  count = count + 1
print('-------------')
# %%
for i in [1,2,3,45,6,78] :
  print(i)
# %%
for i in range(10) :
  print(i)
print("-----------------------")
for i in range(95, 100) :
  print(i)
print("--------------------")
for i in range(0,5,2) :
  print(i)
# %%
for i in range(5) :
  for j in range(i+1) :
    print("*", end="") #줄바꿈 안함
  print()
# %%
limit = 5
count = 0
while True :
  if count > limit :
    break
  count = count + 1
  print(f'loop! {count}')
# %%
for i in range(10) :
  if i%2 :
    continue
  print(i) # 짝수만 출력
