echo "\033[93mDeleting previous contest file \033[0m"
rm -rf {A..Z}
echo "\033[93mSetting up contest url\033[0m"
echo "CONTEST_URL=$1" | tee .env
echo "\033[93mRunning 'script' to setup contest environment\033[0m"
node script