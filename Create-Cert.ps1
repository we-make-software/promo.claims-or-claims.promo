# Create a self-signed certificate
$cert = New-SelfSignedCertificate -Type CodeSigningCert -Subject "CN=WeMakeSoftwareDev" -KeyUsage DigitalSignature -KeyExportPolicy Exportable -Provider "Microsoft Enhanced RSA and AES Cryptographic Provider" -HashAlgorithm SHA256 -CertStoreLocation "Cert:\LocalMachine\My"

# Define the paths for the exported certificate files
$pfxPath = "C:\WeMakeSoftwareDev.pfx"
$cerPath = "C:\WeMakeSoftwareDev.cer"

# Export the certificate and private key to a PFX file with a password
$pfxPassword = ConvertTo-SecureString -String "Your@Password" -Force -AsPlainText
Export-PfxCertificate -Cert "Cert:\LocalMachine\My\$($cert.Thumbprint)" -FilePath $pfxPath -Password $pfxPassword

# Export the public certificate to a CER file
Export-Certificate -Cert "Cert:\LocalMachine\My\$($cert.Thumbprint)" -FilePath $cerPath
