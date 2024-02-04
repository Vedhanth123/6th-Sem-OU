from nltk.book import *
from matplotlib.pyplot import *

# print("This is the output-----------------")
# text2.similar("monstrous")

# print("THis is the ouput of concordance")
# text2.concordance("monstrous")

# print("THis is the ouput of commonn_contexts")
# text2.common_contexts(['monstrous', 'very'])

print("THis is the ouput of dispersion_plot")
text4.dispersion_plot(['citizens','democracy','freedom','duties','america'])
show()

print("THis is the ouput of generate")
text3.generate()
