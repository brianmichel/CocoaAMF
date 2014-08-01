Pod::Spec.new do |s|
  s.name         = "CocoaAMF"
  s.version      = "1.2.0"
  s.summary      = "CocoaAMF is a set of classes which can make AMF0 and AMF3 remoting calls or act as a server to handle AMF requests."
  s.description  = <<-DESC
  Action Message Format (AMF) is a binary format used to serialize object graphs such as ActionScript objects and XML, or send messages between an Adobe Flash client and a remote service, usually a Flash Media Server or third party alternatives. The Actionscript 3 language provides classes for encoding and decoding from the AMF format.
The format is often used in conjunction with Adobe's RTMP to establish connections and control commands for the delivery of streaming media. In this case, the AMF data is encapsulated in a chunk which has a header which defines things such as the message length and type (whether it is a "ping", "command" or media data).
  DESC
  s.homepage     = "https://github.com/jold/CocoaAMF"
  s.license      = { :type => 'MIT', :file => 'LICENSE.txt' }
  s.author       = { "Marc Bauer" => "mb@nesium.com" }
  s.source       = { :git => "https://github.com/jold/CocoaAMF.git", 
                     :tag => "v#{s.version}" }
  
  s.ios.deployment_target = '6.0'
  s.osx.deployment_target = '10.8'
  s.requires_arc = false
  s.source_files = 'CocoaAMF/*.{h,m}'
end
