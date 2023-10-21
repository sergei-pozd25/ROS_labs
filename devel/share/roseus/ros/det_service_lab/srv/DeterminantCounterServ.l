;; Auto-generated. Do not edit!


(when (boundp 'det_service_lab::DeterminantCounterServ)
  (if (not (find-package "DET_SERVICE_LAB"))
    (make-package "DET_SERVICE_LAB"))
  (shadow 'DeterminantCounterServ (find-package "DET_SERVICE_LAB")))
(unless (find-package "DET_SERVICE_LAB::DETERMINANTCOUNTERSERV")
  (make-package "DET_SERVICE_LAB::DETERMINANTCOUNTERSERV"))
(unless (find-package "DET_SERVICE_LAB::DETERMINANTCOUNTERSERVREQUEST")
  (make-package "DET_SERVICE_LAB::DETERMINANTCOUNTERSERVREQUEST"))
(unless (find-package "DET_SERVICE_LAB::DETERMINANTCOUNTERSERVRESPONSE")
  (make-package "DET_SERVICE_LAB::DETERMINANTCOUNTERSERVRESPONSE"))

(in-package "ROS")





(defclass det_service_lab::DeterminantCounterServRequest
  :super ros::object
  :slots (_a11 _a12 _a13 _a21 _a22 _a23 _a31 _a32 _a33 ))

(defmethod det_service_lab::DeterminantCounterServRequest
  (:init
   (&key
    ((:a11 __a11) 0.0)
    ((:a12 __a12) 0.0)
    ((:a13 __a13) 0.0)
    ((:a21 __a21) 0.0)
    ((:a22 __a22) 0.0)
    ((:a23 __a23) 0.0)
    ((:a31 __a31) 0.0)
    ((:a32 __a32) 0.0)
    ((:a33 __a33) 0.0)
    )
   (send-super :init)
   (setq _a11 (float __a11))
   (setq _a12 (float __a12))
   (setq _a13 (float __a13))
   (setq _a21 (float __a21))
   (setq _a22 (float __a22))
   (setq _a23 (float __a23))
   (setq _a31 (float __a31))
   (setq _a32 (float __a32))
   (setq _a33 (float __a33))
   self)
  (:a11
   (&optional __a11)
   (if __a11 (setq _a11 __a11)) _a11)
  (:a12
   (&optional __a12)
   (if __a12 (setq _a12 __a12)) _a12)
  (:a13
   (&optional __a13)
   (if __a13 (setq _a13 __a13)) _a13)
  (:a21
   (&optional __a21)
   (if __a21 (setq _a21 __a21)) _a21)
  (:a22
   (&optional __a22)
   (if __a22 (setq _a22 __a22)) _a22)
  (:a23
   (&optional __a23)
   (if __a23 (setq _a23 __a23)) _a23)
  (:a31
   (&optional __a31)
   (if __a31 (setq _a31 __a31)) _a31)
  (:a32
   (&optional __a32)
   (if __a32 (setq _a32 __a32)) _a32)
  (:a33
   (&optional __a33)
   (if __a33 (setq _a33 __a33)) _a33)
  (:serialization-length
   ()
   (+
    ;; float32 _a11
    4
    ;; float32 _a12
    4
    ;; float32 _a13
    4
    ;; float32 _a21
    4
    ;; float32 _a22
    4
    ;; float32 _a23
    4
    ;; float32 _a31
    4
    ;; float32 _a32
    4
    ;; float32 _a33
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _a11
       (sys::poke _a11 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a12
       (sys::poke _a12 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a13
       (sys::poke _a13 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a21
       (sys::poke _a21 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a22
       (sys::poke _a22 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a23
       (sys::poke _a23 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a31
       (sys::poke _a31 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a32
       (sys::poke _a32 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a33
       (sys::poke _a33 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _a11
     (setq _a11 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a12
     (setq _a12 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a13
     (setq _a13 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a21
     (setq _a21 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a22
     (setq _a22 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a23
     (setq _a23 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a31
     (setq _a31 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a32
     (setq _a32 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a33
     (setq _a33 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass det_service_lab::DeterminantCounterServResponse
  :super ros::object
  :slots (_det ))

(defmethod det_service_lab::DeterminantCounterServResponse
  (:init
   (&key
    ((:det __det) 0.0)
    )
   (send-super :init)
   (setq _det (float __det))
   self)
  (:det
   (&optional __det)
   (if __det (setq _det __det)) _det)
  (:serialization-length
   ()
   (+
    ;; float32 _det
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _det
       (sys::poke _det (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _det
     (setq _det (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass det_service_lab::DeterminantCounterServ
  :super ros::object
  :slots ())

(setf (get det_service_lab::DeterminantCounterServ :md5sum-) "3e8a6a602544480a67a9f07dbdeee698")
(setf (get det_service_lab::DeterminantCounterServ :datatype-) "det_service_lab/DeterminantCounterServ")
(setf (get det_service_lab::DeterminantCounterServ :request) det_service_lab::DeterminantCounterServRequest)
(setf (get det_service_lab::DeterminantCounterServ :response) det_service_lab::DeterminantCounterServResponse)

(defmethod det_service_lab::DeterminantCounterServRequest
  (:response () (instance det_service_lab::DeterminantCounterServResponse :init)))

(setf (get det_service_lab::DeterminantCounterServRequest :md5sum-) "3e8a6a602544480a67a9f07dbdeee698")
(setf (get det_service_lab::DeterminantCounterServRequest :datatype-) "det_service_lab/DeterminantCounterServRequest")
(setf (get det_service_lab::DeterminantCounterServRequest :definition-)
      "float32 a11
float32 a12
float32 a13
float32 a21
float32 a22
float32 a23
float32 a31
float32 a32
float32 a33
---
float32 det

")

(setf (get det_service_lab::DeterminantCounterServResponse :md5sum-) "3e8a6a602544480a67a9f07dbdeee698")
(setf (get det_service_lab::DeterminantCounterServResponse :datatype-) "det_service_lab/DeterminantCounterServResponse")
(setf (get det_service_lab::DeterminantCounterServResponse :definition-)
      "float32 a11
float32 a12
float32 a13
float32 a21
float32 a22
float32 a23
float32 a31
float32 a32
float32 a33
---
float32 det

")



(provide :det_service_lab/DeterminantCounterServ "3e8a6a602544480a67a9f07dbdeee698")


