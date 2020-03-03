# NamedEntityRecognition

In named entity recognition, one tries to find the strings within a text that correspond to proper names (excluding TIME and MONEY) and classify the type of entity denoted by these strings. The problem is difficult partly due to the ambiguity in sentence segmentation; one needs to extract which words belong to a named entity, and which not. Another difficulty occurs when some word may be used as a name of either a person, an organization or a location. For example, Deniz may be used as the name of a person, or - within a compound - it can refer to a location Marmara Denizi 'Marmara Sea', or an organization Deniz Taşımacılık 'Deniz Transportation'.

The standard approach for NER is a word-by-word classification, where the classifier is trained to label the words in the text with tags that indicate the presence of particular kinds of named entities. After giving the class labels (named entity tags) to our training data, the next step is to select a group of features to discriminate different named entities for each input word.

[<sub>ORG</sub> Türk Hava Yolları] bu [<sub>TIME</sub> Pazartesi'den] itibaren [<sub>LOC</sub> İstanbul] [<sub>LOC</sub> Ankara] hattı için indirimli satışlarını [<sub>MONEY</sub> 90 TL'den] başlatacağını açıkladı.

[<sub>ORG</sub> Turkish Airlines] announced that from this [<sub>TIME</sub> Monday] on it will start its discounted fares of [<sub>MONEY</sub> 90TL] for [<sub>LOC</sub> İstanbul] [<sub>LOC</sub> Ankara] route.

See the Table below for typical generic named entity types.

|Tag|Sample Categories|
|---|---|
|PERSON|people, characters|
|ORGANIZATION|companies, teams|
|LOCATION|regions, mountains, seas|
|TIME|time expressions|
|MONEY|monetarial expressions|

-------------------------------
You can also see either [Python](https://github.com/olcaytaner/TurkishNamedEntityRecognition-Py) 
or [Java](https://github.com/olcaytaner/TurkishNamedEntityRecognition) repository.

