import pymongo

client = pymongo.MongoClient("localhost")

mydb = client['Company']

com = mydb.cust

count  = com.count_documents({})
print("Total entries is  : " , count)
print("")

query = {
"firstName":"James","lastName":"Smith","age":20,
"Address":{"street""Address":"777 Brockton Avenue","city":"Abington","state":"MA","postalCode":2351},
"phonenumber":[{"type":"home","number":4661632082},{"type":"fax","number":2899829351}],
"emailAddress":["jamesS@gamil.com","SJames@gmail.com"]
}

com.insert_one(query)

com.insert_many([
{"firstName":"Michael","lastName":"Smith","age":21,
"Address":{"street""Address":"279 Troy Road","city":"East Greenbush","state":"NY","postalCode":12061},
"phonenumber":[{"type":"home","number":9808191199},{"type":"fax","number":7797374941}],
"emailAddress":["MichS@gamil.com","SMich@gmail.com"]},
{"firstName":"Robert","lastName":"Smith","age":22,
"Address":{"street""Address":"1400 Farmington Ave","city":"Bristol","state":"CT","postalCode":6010},
"phonenumber":[{"type":"home","number":1761266808},{"type":"fax","number":9841911399}],
"emailAddress":["Robert@gamil.com","SRob@gmail.com"]},
{"firstName":"Maria","lastName":"Garcia","age":22,
"Address":{"street""Address":"515 Sawmill Road","city":"West Haven","state":"CT","postalCode":6516},
"phonenumber":[{"type":"home","number":8215484894},{"type":"fax","number":6754261777}],
"emailAddress":["MariaG@gamil.com","GMaria@gmail.com"]},
{"firstName":"David","lastName":"Smith","age":21,
"Address":{"street""Address":"30 Memorial Drive","city":"Avon","state":"MA","postalCode":2322},
"phonenumber":[{"type":"home","number":1508518145},{"type":"fax","number":6778131732}],
"emailAddress":["David@gamil.com","SDavid@gmail.com"]},
{"firstName":"Maria","lastName":"Rodriguez","age":20,
"Address":{"street""Address":"100 Thruway Plaza","city":"Cheektowaga","state":"NY","postalCode":14225},
"phonenumber":[{"type":"home","number":2870577148},{"type":"fax","number":1700918899}],
"emailAddress":["MariaR@gamil.com","RMaria@gmail.com"]},
{"firstName":"Mary","lastName":"Smith","age":22,
"Address":{"street""Address":"180 River Rd","city":"Lisbon","state":"CT","postalCode":6351},
"phonenumber":[{"type":"home","number":9806068527},{"type":"fax","number":3219935317}],
"emailAddress":["Mary@gamil.com","SMary@gmail.com"]},
{"firstName":"Maria","lastName":"Hernandez","age":21,
"Address":{"street""Address":"540 West Bypass","city":"Andalusia","state":"AL","postalCode":36420},
"phonenumber":[{"type":"home","number":7655200366},{"type":"fax","number":4381572451}],
"emailAddress":["MariaH@gamil.com","HMaria@gmail.com"]},
{"firstName":"Lilly","lastName":"Martinez","age":22,
"Address":{"street""Address":"591 Memorial Dr","city":"Chicopee","state":"MA","postalCode":1020},
"phonenumber":[{"type":"home","number":1723748378},{"type":"fax","number":3294228998 }],
"emailAddress":["Lilly@gamil.com","MLilly@gmail.com"]},
{"firstName":"James","lastName":"Johnson","age":20,
"Address":{"street""Address":"30 Catskill","city":"Catskill","state":"NY","postalCode":12414},
"phonenumber":[{"type":"home","number":8602583403},{"type":"fax","number":2270838423}],
"emailAddress":["JJames@gamil.com","JohnJames@gmail.com"]},
{"firstName":"Kamilah","lastName":"Earhart","age":32,
"Address":{"street""Address":"297 Grant Avenue","city":"Auburn","state":"NY","postalCode":13021},
"phonenumber":[{"type":"home","number":7360386487},{"type":"fax","number":8330942524}],
"emailAddress":["Kamilah@gamil.com","EKamlish@gmail.com","KamilahEar@gmail,com"]},
{"firstName":"Alise","lastName":"Pickrell","age":29,
"Address":{"street""Address":"4133 Veterans Memorial","city":"Batavia","state":"NY","postalCode":14020},
"phonenumber":[{"type":"home","number":8564397599},{"type":"fax","number":5426189495},{"type":"Mobile","number":3314579129}],
"emailAddress":["AliseP@gamil.com","PAlise@gmail.com"]},
{"firstName":"Leticia","lastName":"Wrobel","age":33,
"Address":{"street""Address":"337 Russell St","city":"Hadley","state":"MA","postalCode":1035},
"phonenumber":[{"type":"home","number":1659846658},{"type":"fax","number":3502899930},{"type":"Mobile","number":8437087134}],
"emailAddress":["Leticia@gamil.com","WLeticia@gmail.com","WrobelL@gmail,com"]},
{"firstName":"Caridad","lastName":"Kendall","age":34,
"Address":{"street""Address":"6265 Brockport","city":"Brockport","state":"NY","postalCode":14420},
"phonenumber":[{"type":"home","number":8602583403},{"type":"fax","number":4326828684}],
"emailAddress":["Caridad@gamil.com","CaridadK@gmail.com"]},
{"firstName":"Michele","lastName":"Gault","age":36,
"Address":{"street""Address":"5399 W Genesse St","city":"Camillus","state":"NY","postalCode":13031},
"phonenumber":[{"type":"home","number":6125582162},{"type":"fax","number":9359925521},{"type":"Mobile","number":3957610776}],
"emailAddress":["MichaelG@gamil.com","GMichele@gmail.com","GaultM@gmail,com"]},
{"firstName":"Azalee","lastName":"Racey","age":31,
"Address":{"street""Address":"3191 County rd 10","city":"Canandaigua","state":"NY","postalCode":14424},
"phonenumber":[{"type":"home","number":8268801323},{"type":"fax","number":9568588641},{"type":"Mobile","number":7806366159}],
"emailAddress":["AzaleeR@gamil.com","RAzalee@gmail.com"]},
{"firstName":"Kathlyn","lastName":"Hackenberg","age":31,
"Address":{"street""Address":"20 Soojian Dr","city":"Leicester","state":"MA","postalCode":1524},
"phonenumber":[{"type":"home","number":4131667434},{"type":"fax","number":4051166104}],
"emailAddress":["Kathlyn@gamil.com","HKathlyn@gmail.com"]},
{"firstName":"Edie","lastName":"Burstein","age":38,
"Address":{"street""Address":"30 Catskill","city":"Catskill","state":"NY","postalCode":12414},
"phonenumber":[{"type":"home","number":2601886547},{"type":"fax","number":2999933858}],
"emailAddress":["Edie@gamil.com","BEdie@gmail.com","BursteinE@gmail,com"]},
{"firstName":"Will","lastName":"Strout","age":36,
"Address":{"street""Address":"11 Jungle Road","city":"Leominster","state":"MA","postalCode":1453},
"phonenumber":[{"type":"home","number":9764636612},{"type":"fax","number":8685337904},{"type":"Mobile","number":9809039510}],
"emailAddress":["Will@gamil.com","SWill@gmail.com"]},
{"firstName":"Cesar","lastName":"Bannon","age":34,
"Address":{"street""Address":"161 Centereach Mall","city":"Centereach","state":"NY","postalCode":11720},
"phonenumber":[{"type":"home","number":8803053048},{"type":"fax","number":8337163141},{"type":"Mobile","number":9735653616}],
"emailAddress":["Cesar@gamil.com","BCesar@gmail.com"]},
{"firstName":"Hanna","lastName":"Voliva","age":30,
"Address":{"street""Address":"780 Lynnway","city":"Lynn","state":"MA","postalCode":1905},
"phonenumber":[{"type":"home","number":4041954879},{"type":"fax","number":2490539545}],
"emailAddress":["Hanna@gamil.com","VHanna@gmail.com","VolivaHanna@gmail,com"]},
{"firstName":"Yuonne","lastName":"Gingerich","age":22,
"Address":{"street""Address":"3018 East Ave","city":"Central Square","state":"NY","postalCode":13036},
"phonenumber":[{"type":"home","number":2990731778},{"type":"fax","number":4631531140},{"type":"Mobile","number":8829936546}],
"emailAddress":["Yuonne@gamil.com","GYuonne@gmail.com"]},
{"firstName":"Jackie","lastName":"Wolfenbarger","age":22,
"Address":{"street""Address":"100 Thruway Plaza","city":"Cheektowaga","state":"NY","postalCode":14225},
"phonenumber":[{"type":"home","number":6822716568},{"type":"fax","number":7965807774}],
"emailAddress":["Jackie@gamil.com","WJackie@gmail.com"]},
])
print("")

print("number of entries after insertion")
count  = com.count_documents({})
print("Total entries : " , count)

#   increase "age" 
print("increase age")
print(com.find_one({"firstName":"Michael","lastName":"Smith"}))
com.update_one({"firstName":"Michael","lastName":"Smith"},{"$inc":{"age":2}})
print(com.find_one({"firstName":"Michael","lastName":"Smith"}))
print("")
#for record in com.find({'"S_id"': 'S112'}):
#    print(record)

#    push emailAddress
print("push emailaddress")
com.update_one({"firstName":"Michael","lastName":"Smith"},{"$push":{"emailAddress":{"$each":["SmithMich@gmail.com"]}}})
print(com.find_one({"firstName":"Michael","lastName":"Smith"}))
print("")

#     pop emailAddress
print("pop emailaddress")
com.update_one({"firstName":"Michael","lastName":"Smith"},{"$pop":{"emailAddress":-1}})
print(com.find_one({"firstName":"Michael","lastName":"Smith"}))
print("")

#     updating the "Address"
print("updating the Address")
com.update_one({"firstName":"Michael","lastName":"Smith"},{"$set":{"Address":{"state":"CT","Pincode":4123}}})
print(com.find_one({"firstName":"Michael","lastName":"Smith"}))
print("")

#     updating multiple for age
print("updating multiple for age")
for record in com.find({"lastName":"Smith"}):
    print(record)
com.update_many({"lastName":"Smith"},{"$set":{"age":"28"}})
print("")
for record in com.find({"lastName":"Smith"}):
    print(record)
print("")


#      greater then 
print("greater then")
for record in com.find({"age":{"$gt":28}}):
    print(record)
print("")

#      Sorting in decending order
print("Sorting in decending order")
doc = com.find().sort("firstName",-1)
for x in doc:
  print(x)
print("")

#      Sorting in accending
doc = com.find().sort("S_name",1)
for x in doc:
  print(x)
print("")


#      Name starting with M
print("Name starting with M")
for x in com.find({"firstName":{"$regex":"^M"}}):
  print(x)
print("")


#      delete multiple entries 
print("delete multiple entries having lastName Smith")
count  = com.count_documents({})
print("Total entries : " , count)
print("")
com.delete_many({"lastName":"Smith"})
count  = com.count_documents({})
print("Total entries : " , count)
print("")

#      Droping Collecion
#com.drop()

