; Auto-generated. Do not edit!


(cl:in-package jimmy-msg)


;//! \htmlinclude jimmy_gesture.msg.html

(cl:defclass <jimmy_gesture> (roslisp-msg-protocol:ros-message)
  ((cmd
    :reader cmd
    :initarg :cmd
    :type cl:integer
    :initform 0)
   (param
    :reader param
    :initarg :param
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass jimmy_gesture (<jimmy_gesture>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <jimmy_gesture>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'jimmy_gesture)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name jimmy-msg:<jimmy_gesture> is deprecated: use jimmy-msg:jimmy_gesture instead.")))

(cl:ensure-generic-function 'cmd-val :lambda-list '(m))
(cl:defmethod cmd-val ((m <jimmy_gesture>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader jimmy-msg:cmd-val is deprecated.  Use jimmy-msg:cmd instead.")
  (cmd m))

(cl:ensure-generic-function 'param-val :lambda-list '(m))
(cl:defmethod param-val ((m <jimmy_gesture>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader jimmy-msg:param-val is deprecated.  Use jimmy-msg:param instead.")
  (param m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <jimmy_gesture>) ostream)
  "Serializes a message object of type '<jimmy_gesture>"
  (cl:let* ((signed (cl:slot-value msg 'cmd)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'param))))
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
   (cl:slot-value msg 'param))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <jimmy_gesture>) istream)
  "Deserializes a message object of type '<jimmy_gesture>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cmd) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'param) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'param)))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<jimmy_gesture>)))
  "Returns string type for a message object of type '<jimmy_gesture>"
  "jimmy/jimmy_gesture")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'jimmy_gesture)))
  "Returns string type for a message object of type 'jimmy_gesture"
  "jimmy/jimmy_gesture")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<jimmy_gesture>)))
  "Returns md5sum for a message object of type '<jimmy_gesture>"
  "a965d31aafc3ca30eff567cfc7155caf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'jimmy_gesture)))
  "Returns md5sum for a message object of type 'jimmy_gesture"
  "a965d31aafc3ca30eff567cfc7155caf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<jimmy_gesture>)))
  "Returns full string definition for message of type '<jimmy_gesture>"
  (cl:format cl:nil "#basically a list of gestures as noted in config file~%~%int32 cmd~%float64[] param  ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'jimmy_gesture)))
  "Returns full string definition for message of type 'jimmy_gesture"
  (cl:format cl:nil "#basically a list of gestures as noted in config file~%~%int32 cmd~%float64[] param  ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <jimmy_gesture>))
  (cl:+ 0
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'param) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <jimmy_gesture>))
  "Converts a ROS message object to a list"
  (cl:list 'jimmy_gesture
    (cl:cons ':cmd (cmd msg))
    (cl:cons ':param (param msg))
))
