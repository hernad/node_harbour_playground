{

 'conditions': [
    ['OS!="win"', {
      'variables': {
        'HB_Root%': '/opt/knowhowERP/hbout',
        'GTK_Root%': 'C:/GTK',  # Set the location of GTK all-in-one bundle
        'with_jpeg%': 'false',
        'with_gif%': 'false',
        'with_pango%': 'false'
      }
    } 
    ]
  ],

  "targets": [
    {
      "target_name": "hello",
      "sources": [ "hello.cc", "node_0.c" ],
      'conditions': [

        [ 'OS=="linux"',{
                #'ldflags': [ '-Bstatic -lhbct' ],
                #'ldflags': [ '--export-dynamic' ],
                #'cflags': [ '-c -O3  -g -W -Wall -pipe' ],
                #'cflags_cc': [ '-c -O3  -g -W -Wall -pipe' ],
                #'cflags_cc+': [ '-c -O3  -g -W -Wall -pipe' ]
                #'ldflags': [ '<!@(pkg-config --libs --libs-only-other opencv)' ],
                #'libraries': [ '<!@(pkg-config --libs opencv)' ],
                #'cflags': [ '<!@(pkg-config --cflags opencv)' ],
                #'cflags_cc': [ '<!@(pkg-config --cflags opencv)' ],
                #'cflags_cc!': ['-fno-rtti'],
                #'cflags_cc+': ['-frtti'],
                'libraries': [
                   '-L<(HB_Root)/lib/harbour',
                   '-L/usr/lib',
                   '-Wl,--start-group -lhbextern -lhbdebug -lhbvm -lhbrtl',
                   '-lhblang -lhbcpage',
                   '-lgtstd -lgttrm',
                   '-lhbrdd -lhbuddall -lhbusrrdd',
                   '-lrddntx -lrddcdx -lrddfpt -lhbrdd -lhbhsx -lhbsix',
                   '-lhbmacro -lhbcplr -lhbpp -lhbcommon -lm -ldl -lrt -lz -lhbpcre',
                   '-Wl,--end-group',
                   '-lharbour'
                 ],
                'include_dirs': [
                   '<(HB_Root)/include/harbour'
                ]
        }],

        ['OS=="mac"', {
          'libraries': [
            '-L<(HB_Root)/lib/harbour',
            '-L/usr/lib',
            #'-lhbct',
            #'-lpq',
            #'-lhbpgsql',
            #'-lhbtip',
            #'-lmysqlclient',
            #'-lminizip',
            #'-lhbmzip',
            '-lgtstd',
            #'-lhbdebug',
            #'-lnode_0',
            #'-Wl,-Bdynamic',
            '-lharbour'
          ],
          'include_dirs': [
            '<(HB_Root)/include/harbour',
          ],
          'defines': [
            'snprintf=_snprintf',
            '_USE_MATH_DEFINES'  # for M_PI
          ]
        }
      ],
      ]

    }
  ]

}
