import pymongo

client = pymongo.MongoClient("localhost")

mydb = client['Institute']

com = mydb.Stud

count  = com.count_documents({})
print("Total entries is  : " , count)
print("")

query = {
"S_id":"S111","S_name":"James Smith","Branch":"CSE","Age":20,"Panel":"E",
"Address":{"Area":"Kothrud","City":"Pune","Pincode":412300},
"Subjects":[{"sub_name":"DBMS","score":85},{"sub_name":"TOC","score":81}],
"Area_of_Interest":["DBMS","Networking"]
}

com.insert_one(query)

com.insert_many([
{"S_id":"S112","S_name":"Michael Smith","Branch":"CSE","Age":20,"Panel":"E",
"Address":{"Area":"ShivTirth","City":"Pune","Pincode":412301},
"Subjects":[{"sub_name":"DBMS","score":81},{"sub_name":"IS","score":83}],
"Area_of_Interest":["DBMS","AI","ML"]},
{"S_id":"S113","S_name":"Robert Smith","Branch":"ECE","Age":21,"Panel":"A",
"Address":{"Area":"Swargate","City":"Pune","Pincode":412303},
"Subjects":[{"sub_name":"AI","score":79},{"sub_name":"TOC","score":80}],
"Area_of_Interest":["DBMS","AI","ML","Networking"]},
{"S_id":"S114","S_name":"Maria Garcia","Branch":"MECH","Age":21,"Panel":"A",
"Address":{"Area":"Shivajinagar","City":"Pune","Pincode":412307},
"Subjects":[{"sub_name":"IS","score":90},{"sub_name":"AI","score":82}],
"Area_of_Interest":["DBMS","Networking"]},
{"S_id":"S115","S_name":"David Smith","Branch":"ECE","Age":20,"Panel":"B",
"Address":{"Area":"Kothrud","City":"Pune","Pincode":412300},
"Subjects":[{"sub_name":"TOC","score":78},{"sub_name":"AI","score":80}],
"Area_of_Interest":["AI","DS"]},
{"S_id":"S116","S_name":"Maria Rodriguez","Branch":"CSE","Age":21,"Panel":"B",
"Address":{"Area":"Sangamvadi","City":"Pune","Pincode":412311},
"Subjects":[{"sub_name":"IS","score":72},{"sub_name":"TOC","score":75}],
"Area_of_Interest":["Networking","DWDM","OS"]},
{"S_id":"S117","S_name":"Mary Smith","Branch":"Civil","Age":20,"Panel":"C",
"Address":{"Area":"Hadapsar","City":"Pune","Pincode":412312},
"Subjects":[{"sub_name":"TOC","score":92},{"sub_name":"IS","score":93}],
"Area_of_Interest":["DBMS","DWDM","OS"]},
{"S_id":"S118","S_name":"Maria Hernandez","Branch":"Mech","Age":21,"Panel":"E",
"Address":{"Area":"Swargate","City":"Pune","Pincode":412303},
"Subjects":[{"sub_name":"TOC","score":93},{"sub_name":"AI","score":91}],
"Area_of_Interest":["DBMS","Web Dev"]},
{"S_id":"S119","S_name":"Lilly Martinez","Branch":"ECE","Age":20,"Panel":"C",
"Address":{"Area":"Kothrud","City":"Pune","Pincode":412300},
"Subjects":[{"sub_name":"IS","score":81},{"sub_name":"AI","score":90}],
"Area_of_Interest":["AWS","Web Dev"]},
{"S_id":"S120","S_name":"James Johnson","Branch":"CSE","Age":21,"Panel":"C",
"Address":{"Area":"Kothrud","City":"Pune","Pincode":412300},
"Subjects":[{"sub_name":"DBMS","score":83},{"sub_name":"AI","score":87}],
"Area_of_Interest":["AWS","Develops"]},
])
print("")

print("Number of entries after insertion")
count  = com.count_documents({})
print("Total entries : " , count)

#   increase age 
print("increase age")
print(com.find_one({"S_id":"S111"}))
com.update_one({"S_id":"S111"},{"$inc":{"Age":2}})
print(com.find_one({"S_id": 'S111'}))
print("")
#for record in com.find({'"S_id"': 'S112'}):
#    print(record)

#    push area of interest
print("push area of interest")
com.update_one({"S_id":"S111"},{"$push":{"Area_of_Interest":{"$each":["NLP"]}}})
print(com.find_one({"S_id": 'S111'}))
print("")

#     pop subject
print("pop subject")
com.update_one({"S_id":"S111"},{"$pop":{"Subjects":-1}})
print(com.find_one({"S_id": 'S111'}))
print("")

#     updating the address
print("updating the address")
com.update_one({"S_id":"S111"},{"$set":{"Branch":"Mech","Address":{"Area":"Hadapsar","Pincode":412312}}})
print(com.find_one({"S_id": 'S111'}))
print("")

#     updating multiple for Panel
print("updating multiple for Panel")
for record in com.find({"Panel": "A"}):
    print(record)
com.update_many({"Panel":"B"},{"$set":{"Panel":"A"}})
print("")
for record in com.find({"Panel": "A"}):
    print(record)
print("")


#      greater then 
print("greater then")
for record in com.find({"Age":{"$gt":20}}):
    print(record)
print("")

#      Sorting in decending order
print("Sorting in decending order")
doc = com.find().sort("S_name",-1)
for x in doc:
  print(x)
print("")

'''
#      Sorting in accending
doc = com.find().sort("S_name",1)
for x in doc:
  print(x)
print("")
'''

#      Name starting with M
print("Name starting with M")
for x in com.find({"S_name":{"$regex":"^M"}}):
  print(x)
print("")

#      delete multiple entries 
print("delete multiple entries having Panel C")
count  = com.count_documents({})
print("Total entries : " , count)
print("")
com.delete_many({"Panel":"C"})
count  = com.count_documents({})
print("Total entries : " , count)
print("")

#      Droping Collecion
#com.drop()


