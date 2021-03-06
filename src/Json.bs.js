// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';


function toValidJson (o){
  switch (typeof o){
    case "boolean":
    case "number":
    case "string":
      return o;
    case "function":
      throw new Error("Cannot serialize functions");
    case "object":
      if (Array.isArray(o)){
        return [o.hasOwnProperty("tag") ? o.tag : -1, o.map(toValidJson)];
      }
      throw new Error("Cannot serialize unidentified object [" + o + "].")
  }
};

function fromValidJson (o){
  switch (typeof o){
    case "boolean":
    case "number":
    case "string":
      return o;
    case "function":
      throw new Error("Cannot deserialize functions");
    case "object":
      if (Array.isArray(o)){
        var first = o[0]
        if (first == -1){
          return o[1].map(fromValidJson);
        } else {
          var a = o[1].map(fromValidJson);
          a.tag = first;
          return a
        }
      }
      throw new Error("Cannot deserialize unidentified object [" + o + "].")
  }
};

exports.toValidJson = toValidJson;
exports.fromValidJson = fromValidJson;
/* No side effect */
