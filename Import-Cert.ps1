# Import the certificate into Trusted Root Certification Authorities
Import-Certificate -FilePath $cerPath -CertStoreLocation "Cert:\LocalMachine\Root"
