
(cl:in-package :asdf)

(defsystem "det_service_lab-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "DeterminantCounterServ" :depends-on ("_package_DeterminantCounterServ"))
    (:file "_package_DeterminantCounterServ" :depends-on ("_package"))
  ))