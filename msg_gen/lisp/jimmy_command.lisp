; Auto-generated. Do not edit!


(cl:in-package jimmy-msg)


;//! \htmlinclude jimmy_command.msg.html

(cl:defclass <jimmy_command> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (cmd
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

(cl:defclass jimmy_command (<jimmy_command>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <jimmy_command>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'jimmy_command)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name jimmy-msg:<jimmy_command> is deprecated: use jimmy-msg:jimmy_command instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <jimmy_command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader jimmy-msg:header-val is deprecated.  Use jimmy-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'cmd-val :lambda-list '(m))
(cl:defmethod cmd-val ((m <jimmy_command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader jimmy-msg:cmd-val is deprecated.  Use jimmy-msg:cmd instead.")
  (cmd m))

(cl:ensure-generic-function 'param-val :lambda-list '(m))
(cl:defmethod param-val ((m <jimmy_command>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader jimmy-msg:param-val is deprecated.  Use jimmy-msg:param instead.")
  (param m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<jimmy_command>)))
    "Constants for message type '<jimmy_command>"
  '((:CMD_NECK . -2)
    (:CMD_SAVE_AND_QUIT . -1)
    (:CMD_IDLE . 0)
    (:CMD_WALK . 1)
    (:CMD_GESTURE_START . 2))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'jimmy_command)))
    "Constants for message type 'jimmy_command"
  '((:CMD_NECK . -2)
    (:CMD_SAVE_AND_QUIT . -1)
    (:CMD_IDLE . 0)
    (:CMD_WALK . 1)
    (:CMD_GESTURE_START . 2))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <jimmy_command>) ostream)
  "Serializes a message object of type '<jimmy_command>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <jimmy_command>) istream)
  "Deserializes a message object of type '<jimmy_command>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<jimmy_command>)))
  "Returns string type for a message object of type '<jimmy_command>"
  "jimmy/jimmy_command")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'jimmy_command)))
  "Returns string type for a message object of type 'jimmy_command"
  "jimmy/jimmy_command")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<jimmy_command>)))
  "Returns md5sum for a message object of type '<jimmy_command>"
  "2a88fad4ecf04f86731a30af3dfd54d2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'jimmy_command)))
  "Returns md5sum for a message object of type 'jimmy_command"
  "2a88fad4ecf04f86731a30af3dfd54d2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<jimmy_command>)))
  "Returns full string definition for message of type '<jimmy_command>"
  (cl:format cl:nil "Header header~%~%int32 CMD_NECK                = -2~%int32 CMD_SAVE_AND_QUIT       = -1~%int32 CMD_IDLE                = 0~%int32 CMD_WALK                = 1~%int32 CMD_GESTURE_START       = 2~%# 3 and higher are gestures~%~%int32 cmd~%float64[] param  ~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'jimmy_command)))
  "Returns full string definition for message of type 'jimmy_command"
  (cl:format cl:nil "Header header~%~%int32 CMD_NECK                = -2~%int32 CMD_SAVE_AND_QUIT       = -1~%int32 CMD_IDLE                = 0~%int32 CMD_WALK                = 1~%int32 CMD_GESTURE_START       = 2~%# 3 and higher are gestures~%~%int32 cmd~%float64[] param  ~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <jimmy_command>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'param) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <jimmy_command>))
  "Converts a ROS message object to a list"
  (cl:list 'jimmy_command
    (cl:cons ':header (header msg))
    (cl:cons ':cmd (cmd msg))
    (cl:cons ':param (param msg))
))
