; Auto-generated. Do not edit!


(cl:in-package det_service_lab-srv)


;//! \htmlinclude DeterminantCounterServ-request.msg.html

(cl:defclass <DeterminantCounterServ-request> (roslisp-msg-protocol:ros-message)
  ((a11
    :reader a11
    :initarg :a11
    :type cl:float
    :initform 0.0)
   (a12
    :reader a12
    :initarg :a12
    :type cl:float
    :initform 0.0)
   (a13
    :reader a13
    :initarg :a13
    :type cl:float
    :initform 0.0)
   (a21
    :reader a21
    :initarg :a21
    :type cl:float
    :initform 0.0)
   (a22
    :reader a22
    :initarg :a22
    :type cl:float
    :initform 0.0)
   (a23
    :reader a23
    :initarg :a23
    :type cl:float
    :initform 0.0)
   (a31
    :reader a31
    :initarg :a31
    :type cl:float
    :initform 0.0)
   (a32
    :reader a32
    :initarg :a32
    :type cl:float
    :initform 0.0)
   (a33
    :reader a33
    :initarg :a33
    :type cl:float
    :initform 0.0))
)

(cl:defclass DeterminantCounterServ-request (<DeterminantCounterServ-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DeterminantCounterServ-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DeterminantCounterServ-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name det_service_lab-srv:<DeterminantCounterServ-request> is deprecated: use det_service_lab-srv:DeterminantCounterServ-request instead.")))

(cl:ensure-generic-function 'a11-val :lambda-list '(m))
(cl:defmethod a11-val ((m <DeterminantCounterServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader det_service_lab-srv:a11-val is deprecated.  Use det_service_lab-srv:a11 instead.")
  (a11 m))

(cl:ensure-generic-function 'a12-val :lambda-list '(m))
(cl:defmethod a12-val ((m <DeterminantCounterServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader det_service_lab-srv:a12-val is deprecated.  Use det_service_lab-srv:a12 instead.")
  (a12 m))

(cl:ensure-generic-function 'a13-val :lambda-list '(m))
(cl:defmethod a13-val ((m <DeterminantCounterServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader det_service_lab-srv:a13-val is deprecated.  Use det_service_lab-srv:a13 instead.")
  (a13 m))

(cl:ensure-generic-function 'a21-val :lambda-list '(m))
(cl:defmethod a21-val ((m <DeterminantCounterServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader det_service_lab-srv:a21-val is deprecated.  Use det_service_lab-srv:a21 instead.")
  (a21 m))

(cl:ensure-generic-function 'a22-val :lambda-list '(m))
(cl:defmethod a22-val ((m <DeterminantCounterServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader det_service_lab-srv:a22-val is deprecated.  Use det_service_lab-srv:a22 instead.")
  (a22 m))

(cl:ensure-generic-function 'a23-val :lambda-list '(m))
(cl:defmethod a23-val ((m <DeterminantCounterServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader det_service_lab-srv:a23-val is deprecated.  Use det_service_lab-srv:a23 instead.")
  (a23 m))

(cl:ensure-generic-function 'a31-val :lambda-list '(m))
(cl:defmethod a31-val ((m <DeterminantCounterServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader det_service_lab-srv:a31-val is deprecated.  Use det_service_lab-srv:a31 instead.")
  (a31 m))

(cl:ensure-generic-function 'a32-val :lambda-list '(m))
(cl:defmethod a32-val ((m <DeterminantCounterServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader det_service_lab-srv:a32-val is deprecated.  Use det_service_lab-srv:a32 instead.")
  (a32 m))

(cl:ensure-generic-function 'a33-val :lambda-list '(m))
(cl:defmethod a33-val ((m <DeterminantCounterServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader det_service_lab-srv:a33-val is deprecated.  Use det_service_lab-srv:a33 instead.")
  (a33 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DeterminantCounterServ-request>) ostream)
  "Serializes a message object of type '<DeterminantCounterServ-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a11))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a12))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a13))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a21))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a22))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a23))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a31))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a32))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a33))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DeterminantCounterServ-request>) istream)
  "Deserializes a message object of type '<DeterminantCounterServ-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a11) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a12) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a13) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a21) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a22) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a23) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a31) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a32) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a33) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DeterminantCounterServ-request>)))
  "Returns string type for a service object of type '<DeterminantCounterServ-request>"
  "det_service_lab/DeterminantCounterServRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DeterminantCounterServ-request)))
  "Returns string type for a service object of type 'DeterminantCounterServ-request"
  "det_service_lab/DeterminantCounterServRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DeterminantCounterServ-request>)))
  "Returns md5sum for a message object of type '<DeterminantCounterServ-request>"
  "3e8a6a602544480a67a9f07dbdeee698")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DeterminantCounterServ-request)))
  "Returns md5sum for a message object of type 'DeterminantCounterServ-request"
  "3e8a6a602544480a67a9f07dbdeee698")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DeterminantCounterServ-request>)))
  "Returns full string definition for message of type '<DeterminantCounterServ-request>"
  (cl:format cl:nil "float32 a11~%float32 a12~%float32 a13~%float32 a21~%float32 a22~%float32 a23~%float32 a31~%float32 a32~%float32 a33~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DeterminantCounterServ-request)))
  "Returns full string definition for message of type 'DeterminantCounterServ-request"
  (cl:format cl:nil "float32 a11~%float32 a12~%float32 a13~%float32 a21~%float32 a22~%float32 a23~%float32 a31~%float32 a32~%float32 a33~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DeterminantCounterServ-request>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DeterminantCounterServ-request>))
  "Converts a ROS message object to a list"
  (cl:list 'DeterminantCounterServ-request
    (cl:cons ':a11 (a11 msg))
    (cl:cons ':a12 (a12 msg))
    (cl:cons ':a13 (a13 msg))
    (cl:cons ':a21 (a21 msg))
    (cl:cons ':a22 (a22 msg))
    (cl:cons ':a23 (a23 msg))
    (cl:cons ':a31 (a31 msg))
    (cl:cons ':a32 (a32 msg))
    (cl:cons ':a33 (a33 msg))
))
;//! \htmlinclude DeterminantCounterServ-response.msg.html

(cl:defclass <DeterminantCounterServ-response> (roslisp-msg-protocol:ros-message)
  ((det
    :reader det
    :initarg :det
    :type cl:float
    :initform 0.0))
)

(cl:defclass DeterminantCounterServ-response (<DeterminantCounterServ-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DeterminantCounterServ-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DeterminantCounterServ-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name det_service_lab-srv:<DeterminantCounterServ-response> is deprecated: use det_service_lab-srv:DeterminantCounterServ-response instead.")))

(cl:ensure-generic-function 'det-val :lambda-list '(m))
(cl:defmethod det-val ((m <DeterminantCounterServ-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader det_service_lab-srv:det-val is deprecated.  Use det_service_lab-srv:det instead.")
  (det m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DeterminantCounterServ-response>) ostream)
  "Serializes a message object of type '<DeterminantCounterServ-response>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'det))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DeterminantCounterServ-response>) istream)
  "Deserializes a message object of type '<DeterminantCounterServ-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'det) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DeterminantCounterServ-response>)))
  "Returns string type for a service object of type '<DeterminantCounterServ-response>"
  "det_service_lab/DeterminantCounterServResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DeterminantCounterServ-response)))
  "Returns string type for a service object of type 'DeterminantCounterServ-response"
  "det_service_lab/DeterminantCounterServResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DeterminantCounterServ-response>)))
  "Returns md5sum for a message object of type '<DeterminantCounterServ-response>"
  "3e8a6a602544480a67a9f07dbdeee698")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DeterminantCounterServ-response)))
  "Returns md5sum for a message object of type 'DeterminantCounterServ-response"
  "3e8a6a602544480a67a9f07dbdeee698")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DeterminantCounterServ-response>)))
  "Returns full string definition for message of type '<DeterminantCounterServ-response>"
  (cl:format cl:nil "float32 det~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DeterminantCounterServ-response)))
  "Returns full string definition for message of type 'DeterminantCounterServ-response"
  (cl:format cl:nil "float32 det~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DeterminantCounterServ-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DeterminantCounterServ-response>))
  "Converts a ROS message object to a list"
  (cl:list 'DeterminantCounterServ-response
    (cl:cons ':det (det msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'DeterminantCounterServ)))
  'DeterminantCounterServ-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'DeterminantCounterServ)))
  'DeterminantCounterServ-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DeterminantCounterServ)))
  "Returns string type for a service object of type '<DeterminantCounterServ>"
  "det_service_lab/DeterminantCounterServ")