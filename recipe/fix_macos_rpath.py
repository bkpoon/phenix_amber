"""
Tool for initial rpath fix for extensions
"""
from __future__ import absolute_import, division, print_function

import os
import glob
import sys

from subprocess import check_output

# =============================================================================
if __name__ == '__main__':
  ext_file = sys.argv[1]

  libraries = check_output([os.environ['OTOOL'], '-L', ext_file]).decode('utf8').split('\n')
  print('\n'.join(libraries))
  # update id
  new_id = '@rpath/' + libraries[0][:-1].split('/')[-1]
  cmd = [os.environ["INSTALL_NAME_TOOL"], '-id', new_id, ext_file]
  print(' '.join(cmd))
  output = check_output(cmd)
  # update rpath
  prefix = os.environ["MSANDERHOME"]
  for line in libraries[1:]:
    lib = line.replace('\t', '').split()
    if len(lib) > 0:
      lib = lib[0]
      new_lib = None
      if lib.startswith(prefix):
        new_lib = os.path.join('@rpath', lib.split('/')[-1])
      if new_lib is not None:
        cmd = [os.environ["INSTALL_NAME_TOOL"], '-change', lib, new_lib, ext_file]
        print(' '.join(cmd))
        output = check_output(cmd)
