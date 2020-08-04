#Author: vhanla
#Force coloring of git and npm commands 
Clear-Host
$env:TERM = 'cygwin'
$env:TERM = 'FRSX'


$global:foregroundColor = 'white'
$time = Get-Date
$psVersion= $host.Version.Major
$curUser= (Get-ChildItem Env:\USERNAME).Value
$curComp= (Get-ChildItem Env:\COMPUTERNAME).Value

# Write-Host "Hello, $curUser! " -foregroundColor $foregroundColor -NoNewLine; Write-Host "$([char]9829) " -foregroundColor Red
# Write-Host "Today is: $($time.ToLongDateString())"
# Write-Host "Welcome to PowerShell version: $psVersion" -foregroundColor Green
# Write-Host "I am: $curComp" -foregroundColor Green
# Write-Host "¡Let's program!" `n
function Prompt {
    # Prompt Colors
    # Black DarkBlue DarkGreen DarkCyan DarkRed DarkMagenta DarkYellow
    # Gray DarkGray Blue Green Cyan Red Magenta Yellow White

    $prompt_text = "Black"
    $prompt_background = "Blue"
    $prompt_git_background = "Yellow"   
    $prompt_git_text = "Black"  
    
    # Grab Git Branch
    $git_string = "";
    git branch | foreach {
        if ($_ -match "^\* (.*)"){
            $git_string += $matches[1]
        }
    }
    
    # Grab Git Status
    $git_status = "";
    git status --porcelain | foreach {
        $git_status = $_ #just replace other wise it will be empty
    }
    
    # if (!$git_string) {
    #   $prompt_text = "White"
    #   $prompt_background = "DarkMagenta"
    # }
    
    if ($git_status){
        $prompt_git_background = "DarkGreen"
    }
    

    $curtime = Get-Date
    $path = PWD
    Write-Host $path -foregroundColor $prompt_text -backgroundColor $prompt_background -NoNewLine
    if ($git_string){
        Write-Host  "$([char]57520)" -foregroundColor $prompt_background -NoNewLine -backgroundColor $prompt_git_background
        Write-Host  " $([char]57504) " -foregroundColor $prompt_git_text -backgroundColor $prompt_git_background -NoNewLine     
        Write-Host ($git_string)  -NoNewLine -foregroundColor $prompt_git_text -backgroundColor $prompt_git_background
        Write-Host  "$([char]57520)" -foregroundColor $prompt_git_background 
    }
    else{
        Write-Host  "$([char]57520)" -foregroundColor $prompt_background
    }
    Write-Host -NoNewLine "$" -foregroundColor Green 
    Write-Host -NoNewLine "[" -foregroundColor Yellow
    Write-Host -NoNewLine ("{0:HH}:{0:mm}:{0:ss}" -f (Get-Date)) -foregroundColor $foregroundColor
    Write-Host -NoNewLine "]" -foregroundColor Yellow
    Write-Host -NoNewLine "$([char]955)" -foregroundColor Green

    $host.UI.RawUI.WindowTitle = "PS >> User: $curUser >> Current DIR: $((Get-Location).Path)"

    Return " "

}