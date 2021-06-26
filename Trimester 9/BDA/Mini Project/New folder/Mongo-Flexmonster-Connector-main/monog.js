const mongo = require('express').Router();
const mongodb = require("mongodb");
const fm_mongo_connector = require("flexmonster-mongo-connector");

let dbo = null;
let _apiReference = null; // it’ll be the Connector instance

mongodb.MongoClient.connect("mongodb+srv://Divya:<password>@cluster0.2wnb8.mongodb.net/myFirstDatabase?retryWrites=true&w=majority", {
    useNewUrlParser: true
    }, (err, db) => {
        if (err)
            throw err; 
        dbo = db.db("ecommerse");
        _apiReference = new fm_mongo_connector.MongoDataAPI();
}); 

// requests handling functions will appear here
module.exports = mongo;

mongo.post("/handshake", async (req, res) => {
    try {
        res.json({ version: _apiReference.API_VERSION });
    } catch (err) {
         handleError(err, res);
    }
});

mongo.post("/fields", async (req, res) => {
    try {
        const result = await _apiReference.getSchema(dbo, req.body.index);
        res.json(result);
    } catch (err) {
        //your error handler
    }
});

mongo.post("/members", async (req, res) => {
    try {
        const result = await _apiReference.getMembers(
            dbo, req.body.index, req.body.field, 
            { page: req.body.page, pageToken: req.body.pageToken });
        res.json(result);
    } catch (err) {
      //your error handler
    }
});

mongo.post("/select", async (req, res) => {
    try {
        const result = await _apiReference.getSelectResult(
            dbo, req.body.index, req.body.query,
            { page: req.body.page, pageToken: req.body.pageToken });
        res.json(result);
    } catch (err) {
      //your error handler
    }
});