## httpd Module Development on Windows
#### Steps:
* install cygwin with the following packages:
    * httpd
    * httpd-mod
    * cygrunsrv
    * make
    * wget
* Run `/usr/bin/cygserver-config` as admin
* Open `services.msc`, and start `CYGWIN Cygserver`
* create mod_example.c with the following content
* apxs -i -a -c /cygdrive/d/OneDrive/Projects/mod_example/mod_example.c

#### More details/links:
* [request_rec](https://ci.apache.org/projects/httpd/trunk/doxygen/structrequest__rec.html) structure
* [apxs](https://httpd.apache.org/docs/2.4/programs/apxs.html) tool
* [apache module development guide](https://httpd.apache.org/docs/2.4/developer/modguide.html)
* [cygwin+httpd installation steps](https://stackoverflow.com/a/33437349/248406)

#### Useful commands:
* httpd restart: `/usr/sbin/apachectl restart`
