#%% nonlocal / clouser
def do_count() :
  count = 0
  def closer() :
    nonlocal count
    count = count + 1
    print(count)
  return closer

_count = do_count()
_count()
_count()

print(count)