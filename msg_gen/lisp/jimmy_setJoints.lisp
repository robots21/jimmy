; Auto-generated. Do not edit!


(cl:in-package jimmy-msg)


;//! \htmlinclude jimmy_setJoints.msg.html

(cl:defclass <jimmy_setJoints> (roslisp-msg-protocol:ros-message)
  ((positions
    :reader positions
    :initarg :positions
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass jimmy_setJoints (<jimmy_setJoints>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <jimmy_setJoints>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'jimmy_setJoints)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name jimmy-msg:<jimmy_setJoints> is deprecated: use jimmy-msg:jimmy_setJoints instead.")))

(cl:ensure-generic-function 'positions-val :lambda-list '(m))
(cl:defmethod positions-val ((m <jimmy_setJoints>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader jimmy-msg:positions-val is deprecated.  Use jimmy-msg:positions instead.")
  (positions m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <jimmy_setJoints>) ostream)
  "Serializes a message object of type '<jimmy_setJoints>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'positions))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'positions))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <jimmy_setJoints>) istream)
  "Deserializes a message object of type '<jimmy_setJoints>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'positions) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'positions)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<jimmy_setJoints>)))
  "Returns string type for a message object of type '<jimmy_setJoints>"
  "jimmy/jimmy_setJoints")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'jimmy_setJoints)))
  "Returns string type for a message object of type 'jimmy_setJoints"
  "jimmy/jimmy_setJoints")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<jimmy_setJoints>)))
  "Returns md5sum for a message object of type '<jimmy_setJoints>"
  "3b33cf2d1f9005e741ee291d519b97ee")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'jimmy_setJoints)))
  "Returns md5sum for a message object of type 'jimmy_setJoints"
  "3b33cf2d1f9005e741ee291d519b97ee")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<jimmy_setJoints>)))
  "Returns full string definition for message of type '<jimmy_setJoints>"
  (cl:format cl:nil "float64[] positions~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'jimmy_setJoints)))
  "Returns full string definition for message of type 'jimmy_setJoints"
  (cl:format cl:nil "float64[] positions~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <jimmy_setJoints>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'positions) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <jimmy_setJoints>))
  "Converts a ROS message object to a list"
  (cl:list 'jimmy_setJoints
    (cl:cons ':positions (positions msg))
))
