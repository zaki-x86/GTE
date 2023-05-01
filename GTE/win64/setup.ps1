# Don't allow our script to continue if any errors are observed
$ErrorActionPreference = "Stop"

# Check that we have a 'ext' folder
Push-Location -Path "..\..\"
if (!(Test-Path "ext")) {
    New-Item -ItemType Directory -Path "ext"
}
Pop-Location

# Check that we have the SDL2 ext Windows dev library
if (!(Test-Path "..\..\ext\sdl-windows")) {
    Write-Host "Downloading SDL Windows Dev library into ext folder sdl-windows ..."
    $WebClient = New-Object System.Net.WebClient
    $WebClient.DownloadFile("https://www.libsdl.org/release/SDL2-devel-2.0.12-VC.zip", "..\..\ext\SDL2-devel-2.0.12-VC.zip")

    Push-Location -Path "..\..\ext"
        Write-Host "Unzipping SDL Windows Dev library into ext\sdl-windows ..."
        cmd.exe /c 'tar -xf SDL2-devel-2.0.12-VC.zip'
        Move-Item -Path SDL2-2.0.12 -Destination sdl-windows
        Remove-Item -Path SDL2-devel-2.0.12-VC.zip
    Pop-Location
}

# Check that we have the GLEW ext library
if (!(Test-Path "..\..\ext\glew")) {
    Write-Host "Downloading GLEW into ext folder glew ..."
    $WebClient = New-Object System.Net.WebClient
    $WebClient.DownloadFile("https://github.com/nigels-com/glew/releases/download/glew-2.1.0/glew-2.1.0-win32.zip", "..\..\ext\glew-2.1.0-win32.zip")

    Push-Location -Path "..\..\ext"
        Write-Host "Unzipping GLEW library into ext\glew ..."
        cmd.exe /c 'tar -xf glew-2.1.0-win32.zip'
        Move-Item -Path glew-2.1.0 -Destination glew
        Remove-Item -Path glew-2.1.0-win32.zip
    Pop-Location
}