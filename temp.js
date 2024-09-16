db.createCollection("SchemaValidation",{
  validator:{
    $jsonSchema:{
      required:["name","price"],
      properties:{
        name:{
          bsonType:"string",
          description:"must be a string and is required"
        },
        price:{
          bsonType:"number",
          description:"must be a number and is required"
        }
      }  
    }
  }
})

// To modify the schema validation
db.runCommand({
  
    collMod:"SchemaValidation",
    validator:{
      $jsonSchema:{
        required:["name","price","authorName"],
        properties:{
          name:{
            bsonType:"string",
            description:"must be a string and is required"
          },
          price:{
            bsonType:"number",
            description:"must be a number and is required"
          },
          authorName:{
            bsonType:"string",
            description:"must be a string and is required"
          }
        }  
      }
    }
  })



db.Arrays_Collection.findOne({
  Hobbies:'football'
})
