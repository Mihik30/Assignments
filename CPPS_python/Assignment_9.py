#mihik shah
#FY23B1D065
#Assignment 9

from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
import nltk


example_sent = """Short paragraphs are easier to read and understand.
Writing experts recommend paragraphs of no more than 150 words in three to eight sentences.
Paragraphs should never be longer than 250 words.
Vary the lengths of your paragraphs to make them more interesting."""

stop_words = set(stopwords.words('english'))

word_tokens = word_tokenize(example_sent)
# converts the words in word_tokens to lower case and then checks whether
#they are present in stop_words or not
filtered_sentence = [w for w in word_tokens if not w.lower() in stop_words]
#with no lower case conversion
filtered_sentence = []

for w in word_tokens:
    if w not in stop_words:
        filtered_sentence.append(w)

print(word_tokens)
print(filtered_sentence)