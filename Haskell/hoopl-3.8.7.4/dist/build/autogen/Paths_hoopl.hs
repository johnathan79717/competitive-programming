module Paths_hoopl (
    version,
    getBinDir, getLibDir, getDataDir, getLibexecDir,
    getDataFileName
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
catchIO = Exception.catch


version :: Version
version = Version {versionBranch = [3,8,7,4], versionTags = []}
bindir, libdir, datadir, libexecdir :: FilePath

bindir     = "/usr/local/bin"
libdir     = "/usr/local/lib/hoopl-3.8.7.4/ghc-7.6.2"
datadir    = "/usr/local/share/hoopl-3.8.7.4"
libexecdir = "/usr/local/libexec"

getBinDir, getLibDir, getDataDir, getLibexecDir :: IO FilePath
getBinDir = catchIO (getEnv "hoopl_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "hoopl_libdir") (\_ -> return libdir)
getDataDir = catchIO (getEnv "hoopl_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "hoopl_libexecdir") (\_ -> return libexecdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
