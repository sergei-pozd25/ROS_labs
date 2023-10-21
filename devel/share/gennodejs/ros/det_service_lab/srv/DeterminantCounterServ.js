// Auto-generated. Do not edit!

// (in-package det_service_lab.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class DeterminantCounterServRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.a11 = null;
      this.a12 = null;
      this.a13 = null;
      this.a21 = null;
      this.a22 = null;
      this.a23 = null;
      this.a31 = null;
      this.a32 = null;
      this.a33 = null;
    }
    else {
      if (initObj.hasOwnProperty('a11')) {
        this.a11 = initObj.a11
      }
      else {
        this.a11 = 0.0;
      }
      if (initObj.hasOwnProperty('a12')) {
        this.a12 = initObj.a12
      }
      else {
        this.a12 = 0.0;
      }
      if (initObj.hasOwnProperty('a13')) {
        this.a13 = initObj.a13
      }
      else {
        this.a13 = 0.0;
      }
      if (initObj.hasOwnProperty('a21')) {
        this.a21 = initObj.a21
      }
      else {
        this.a21 = 0.0;
      }
      if (initObj.hasOwnProperty('a22')) {
        this.a22 = initObj.a22
      }
      else {
        this.a22 = 0.0;
      }
      if (initObj.hasOwnProperty('a23')) {
        this.a23 = initObj.a23
      }
      else {
        this.a23 = 0.0;
      }
      if (initObj.hasOwnProperty('a31')) {
        this.a31 = initObj.a31
      }
      else {
        this.a31 = 0.0;
      }
      if (initObj.hasOwnProperty('a32')) {
        this.a32 = initObj.a32
      }
      else {
        this.a32 = 0.0;
      }
      if (initObj.hasOwnProperty('a33')) {
        this.a33 = initObj.a33
      }
      else {
        this.a33 = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DeterminantCounterServRequest
    // Serialize message field [a11]
    bufferOffset = _serializer.float32(obj.a11, buffer, bufferOffset);
    // Serialize message field [a12]
    bufferOffset = _serializer.float32(obj.a12, buffer, bufferOffset);
    // Serialize message field [a13]
    bufferOffset = _serializer.float32(obj.a13, buffer, bufferOffset);
    // Serialize message field [a21]
    bufferOffset = _serializer.float32(obj.a21, buffer, bufferOffset);
    // Serialize message field [a22]
    bufferOffset = _serializer.float32(obj.a22, buffer, bufferOffset);
    // Serialize message field [a23]
    bufferOffset = _serializer.float32(obj.a23, buffer, bufferOffset);
    // Serialize message field [a31]
    bufferOffset = _serializer.float32(obj.a31, buffer, bufferOffset);
    // Serialize message field [a32]
    bufferOffset = _serializer.float32(obj.a32, buffer, bufferOffset);
    // Serialize message field [a33]
    bufferOffset = _serializer.float32(obj.a33, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DeterminantCounterServRequest
    let len;
    let data = new DeterminantCounterServRequest(null);
    // Deserialize message field [a11]
    data.a11 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a12]
    data.a12 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a13]
    data.a13 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a21]
    data.a21 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a22]
    data.a22 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a23]
    data.a23 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a31]
    data.a31 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a32]
    data.a32 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a33]
    data.a33 = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 36;
  }

  static datatype() {
    // Returns string type for a service object
    return 'det_service_lab/DeterminantCounterServRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '76bc77bacade00ac116d8d7c449a7fb9';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 a11
    float32 a12
    float32 a13
    float32 a21
    float32 a22
    float32 a23
    float32 a31
    float32 a32
    float32 a33
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DeterminantCounterServRequest(null);
    if (msg.a11 !== undefined) {
      resolved.a11 = msg.a11;
    }
    else {
      resolved.a11 = 0.0
    }

    if (msg.a12 !== undefined) {
      resolved.a12 = msg.a12;
    }
    else {
      resolved.a12 = 0.0
    }

    if (msg.a13 !== undefined) {
      resolved.a13 = msg.a13;
    }
    else {
      resolved.a13 = 0.0
    }

    if (msg.a21 !== undefined) {
      resolved.a21 = msg.a21;
    }
    else {
      resolved.a21 = 0.0
    }

    if (msg.a22 !== undefined) {
      resolved.a22 = msg.a22;
    }
    else {
      resolved.a22 = 0.0
    }

    if (msg.a23 !== undefined) {
      resolved.a23 = msg.a23;
    }
    else {
      resolved.a23 = 0.0
    }

    if (msg.a31 !== undefined) {
      resolved.a31 = msg.a31;
    }
    else {
      resolved.a31 = 0.0
    }

    if (msg.a32 !== undefined) {
      resolved.a32 = msg.a32;
    }
    else {
      resolved.a32 = 0.0
    }

    if (msg.a33 !== undefined) {
      resolved.a33 = msg.a33;
    }
    else {
      resolved.a33 = 0.0
    }

    return resolved;
    }
};

class DeterminantCounterServResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.det = null;
    }
    else {
      if (initObj.hasOwnProperty('det')) {
        this.det = initObj.det
      }
      else {
        this.det = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DeterminantCounterServResponse
    // Serialize message field [det]
    bufferOffset = _serializer.float32(obj.det, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DeterminantCounterServResponse
    let len;
    let data = new DeterminantCounterServResponse(null);
    // Deserialize message field [det]
    data.det = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'det_service_lab/DeterminantCounterServResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6bb9c80a49044a815006ce46b540ce50';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 det
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DeterminantCounterServResponse(null);
    if (msg.det !== undefined) {
      resolved.det = msg.det;
    }
    else {
      resolved.det = 0.0
    }

    return resolved;
    }
};

module.exports = {
  Request: DeterminantCounterServRequest,
  Response: DeterminantCounterServResponse,
  md5sum() { return '3e8a6a602544480a67a9f07dbdeee698'; },
  datatype() { return 'det_service_lab/DeterminantCounterServ'; }
};
