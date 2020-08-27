#%%
from xml.etree.ElementTree import parse
from PIL import Image, ImageDraw
from IPython.display import display

print(f'module load ok')

ori_img = Image.open('../res/tanks/sheet_tanks.png')
#%%
tree = parse('..\\res\\tanks\\sheet_tanks.xml')
rootNode = tree.getroot()
_nodes = rootNode.findall('SubTexture')
for node in _nodes :
  _name = node.attrib['name']
  _x = int(node.attrib['x'])
  _y = int(node.attrib['y'])
  width = int(node.attrib['width'])
  height = int(node.attrib['height'])
  print( f"{_name :32}, {_x:3}, {_y:3}, {width:3}, {height:3}")

  _img_crop = ori_img.crop((_x, _y, _x+width, _y+height))
  display(_img_crop)
  _img_crop.save(f'{_name}')
# %%
