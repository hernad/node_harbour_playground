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
      "sources": [ "hello.cc" ],
      'conditions': [
        ['OS!="win"', {
          'libraries': [
            '-L<(HB_Root)/lib/harbour',
            '-lharbour',
            '-lgtstd',
            '-lnode'
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
