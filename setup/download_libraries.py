# Script for downloading libraries.
#
# Define libraries to download in `libraries` dictionary
# as [directory name]: [download url] pairs

import os
import requests
import tarfile
import tempfile
import zipfile


libraries = {
	'swig': 'https://vorboss.dl.sourceforge.net/project/swig/swigwin/swigwin-4.0.1/swigwin-4.0.1.zip'
}


def download_libraries():
    lib_dir = os.path.join(os.path.dirname(__file__), '..', 'lib')
    if not os.path.isdir(lib_dir) : 
        print("Creating lib directory...")
        os.mkdir(lib_dir)
	

    for name, url in libraries.items():
        target_dir = os.path.join(os.path.dirname(__file__), '..', 'lib', name)
        print(f'Downloading {name}...')
        if os.path.exists(target_dir):
            print('Download skipped, library directory already exists')
            continue

        response = requests.get(url)
        print('Download complete.')

        assert response.ok
    
        with tempfile.TemporaryFile() as tfile:
            tfile.file.write(response.content)
            os.makedirs(target_dir)

            if url.endswith('.zip'):
                print(f'Extracting {name}...')

                zfile = zipfile.ZipFile(tfile.file)
                zfile.extractall(target_dir)

                print(f'Extracting completed.')

            if url.endswith('.tar.gz'):
                print(f'Extracting {name}...')

                tfile.file.seek(0)
                gzfile = tarfile.open(fileobj=tfile.file, mode='r:gz')
                gzfile.extractall(target_dir)

                print(f'Extracting completed.')

if __name__ == '__main__':
	download_libraries()
		
