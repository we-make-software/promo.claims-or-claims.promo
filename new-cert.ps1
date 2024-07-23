# Prompt for a single password to be used for both PFX files
$password = Read-Host -Prompt "Enter password for PFX files" -AsSecureString

# Prompt for file location
$location = Read-Host -Prompt "Enter the location where you want to save the files (e.g., D:\Certs)"

# Prompt for a custom name to replace "WMS"
$customName = Read-Host -Prompt "Enter a custom name to replace 'WMS'"

# Variables
$rootCAName = "CN=${customName}RootCA"
$evCertName = "CN=${customName}IssuedCert"
$rootCAExportPath = "$location\${customName}RootCA"
$evCertExportPath = "$location\${customName}IssuedCert"

# Create Root CA Certificate
$rootCert = New-SelfSignedCertificate -Type Custom -KeySpec Signature -Subject $rootCAName -KeyExportPolicy Exportable -HashAlgorithm sha256 -KeyLength 2048 -CertStoreLocation "Cert:\LocalMachine\My" -KeyUsageProperty Sign -KeyUsage CertSign -NotAfter (Get-Date).AddYears(10)

# Export Root CA Certificate and Private Key
$rootCertThumbprint = $rootCert.Thumbprint
$rootCertPath = "$rootCAExportPath.pfx"
$rootCertCerPath = "$rootCAExportPath.cer"

Export-PfxCertificate -Cert "Cert:\LocalMachine\My\$rootCertThumbprint" -FilePath $rootCertPath -Password $password
Export-Certificate -Cert "Cert:\LocalMachine\My\$rootCertThumbprint" -FilePath $rootCertCerPath

# Create EV Code Signing Certificate with EKU for Code Signing
$evCert = New-SelfSignedCertificate -Type Custom -DnsName "${customName}IssuedCert" -KeyExportPolicy Exportable -HashAlgorithm sha256 -KeyLength 2048 -CertStoreLocation "Cert:\LocalMachine\My" -KeyUsageProperty All -KeyUsage DigitalSignature -Subject $evCertName -Signer $rootCert -NotAfter (Get-Date).AddYears(2) -TextExtension @("2.5.29.37={text}1.3.6.1.5.5.7.3.3")

# Verify that the EV Code Signing Certificate is signed by the Root CA
$evCert | Select-Object -Property Subject, Issuer

# Export EV Code Signing Certificate and Private Key
$evCertThumbprint = $evCert.Thumbprint
$evCertPath = "$evCertExportPath.pfx"
$evCertCerPath = "$evCertExportPath.cer"

Export-PfxCertificate -Cert "Cert:\LocalMachine\My\$evCertThumbprint" -FilePath $evCertPath -Password $password
Export-Certificate -Cert "Cert:\LocalMachine\My\$evCertThumbprint" -FilePath $evCertCerPath

# Install Root CA Certificate to Trusted Root Certification Authorities store
Import-Certificate -FilePath $rootCertCerPath -CertStoreLocation "Cert:\LocalMachine\Root"

Write-Output "Root CA and EV Code Signing Certificates have been created, exported successfully, and the Root CA has been installed in the Trusted Root Certification Authorities store."
Write-Output "Root CA PFX: $rootCertPath"
Write-Output "EV Code Signing PFX: $evCertPath"

Write-Output "`nThank you for using this script. It is made for the class for the Facebook group: https://www.facebook.com/groups/promoclaimsorclaimsprom"
Write-Output "Best regards,"
Write-Output "Pirasath Luxchumykanthan"
