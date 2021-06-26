const express = require("express");
var cors = require('cors');
var bodyParser = require('body-parser');

const app = express();

app.use(cors());
app.use(bodyParser.json());

app.use('/mongo', require('./monog.js'));

var port = process.env.PORT || 9204;
app.listen(port, () => {
    console.log('Example app listening at http://localhost:${9204}')
});